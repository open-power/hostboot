/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pec/reg00014.H $          */
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

#ifndef __PEC_REG00014_H_
#define __PEC_REG00014_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pec
{
#endif


//>> PREP_[EPS_FIR_LOCAL_ACTION1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_FIR_LOCAL_ACTION1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_LOCAL_ACTION1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_FIR_LOCAL_ACTION1]

//>> GET_[EPS_FIR_LOCAL_ACTION1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_FIR_LOCAL_ACTION1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_LOCAL_ACTION1;
#endif
    return fapi2::getScom(i_target, EPS_FIR_LOCAL_ACTION1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1]

//>> PUT_[EPS_FIR_LOCAL_ACTION1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_FIR_LOCAL_ACTION1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return fapi2::putScom(i_target, EPS_FIR_LOCAL_ACTION1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_FIR_LOCAL_ACTION1]


//>> SET_[EPS_FIR_LOCAL_ACTION1_00]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_00]

//>> SET_[EPS_FIR_LOCAL_ACTION1_00]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_00]

//>> SET_[EPS_FIR_LOCAL_ACTION1_00]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_00]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_00]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_00]

//>> GET_[EPS_FIR_LOCAL_ACTION1_00]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_00]

//>> GET_[EPS_FIR_LOCAL_ACTION1_00]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_00]

//>> SET_[EPS_FIR_LOCAL_ACTION1_01]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_01]

//>> SET_[EPS_FIR_LOCAL_ACTION1_01]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_01]

//>> SET_[EPS_FIR_LOCAL_ACTION1_01]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_01]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_01]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_01]

//>> GET_[EPS_FIR_LOCAL_ACTION1_01]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_01]

//>> GET_[EPS_FIR_LOCAL_ACTION1_01]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_01]

//>> SET_[EPS_FIR_LOCAL_ACTION1_02]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_02]

//>> SET_[EPS_FIR_LOCAL_ACTION1_02]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_02]

//>> SET_[EPS_FIR_LOCAL_ACTION1_02]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_02]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_02]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_02]

//>> GET_[EPS_FIR_LOCAL_ACTION1_02]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_02]

//>> GET_[EPS_FIR_LOCAL_ACTION1_02]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_02]

//>> SET_[EPS_FIR_LOCAL_ACTION1_03]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_03]

//>> SET_[EPS_FIR_LOCAL_ACTION1_03]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_03]

//>> SET_[EPS_FIR_LOCAL_ACTION1_03]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_03]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_03]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_03]

//>> GET_[EPS_FIR_LOCAL_ACTION1_03]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_03]

//>> GET_[EPS_FIR_LOCAL_ACTION1_03]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_03]

//>> SET_[EPS_FIR_LOCAL_ACTION1_04]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_04]

//>> SET_[EPS_FIR_LOCAL_ACTION1_04]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_04]

//>> SET_[EPS_FIR_LOCAL_ACTION1_04]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_04]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_04]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_04]

//>> GET_[EPS_FIR_LOCAL_ACTION1_04]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_04]

//>> GET_[EPS_FIR_LOCAL_ACTION1_04]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_04]

//>> SET_[EPS_FIR_LOCAL_ACTION1_05]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_05]

//>> SET_[EPS_FIR_LOCAL_ACTION1_05]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_05]

//>> SET_[EPS_FIR_LOCAL_ACTION1_05]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_05]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_05]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_05]

//>> GET_[EPS_FIR_LOCAL_ACTION1_05]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_05]

//>> GET_[EPS_FIR_LOCAL_ACTION1_05]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_05]

//>> SET_[EPS_FIR_LOCAL_ACTION1_06]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_06]

//>> SET_[EPS_FIR_LOCAL_ACTION1_06]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_06]

//>> SET_[EPS_FIR_LOCAL_ACTION1_06]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_06]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_06]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_06]

//>> GET_[EPS_FIR_LOCAL_ACTION1_06]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_06]

//>> GET_[EPS_FIR_LOCAL_ACTION1_06]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_06]

//>> SET_[EPS_FIR_LOCAL_ACTION1_07]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_07]

//>> SET_[EPS_FIR_LOCAL_ACTION1_07]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_07]

//>> SET_[EPS_FIR_LOCAL_ACTION1_07]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_07]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_07]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_07]

//>> GET_[EPS_FIR_LOCAL_ACTION1_07]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_07]

//>> GET_[EPS_FIR_LOCAL_ACTION1_07]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_07]

//>> SET_[EPS_FIR_LOCAL_ACTION1_08]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_08]

//>> SET_[EPS_FIR_LOCAL_ACTION1_08]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_08]

//>> SET_[EPS_FIR_LOCAL_ACTION1_08]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_08]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_08]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_08]

//>> GET_[EPS_FIR_LOCAL_ACTION1_08]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_08]

//>> GET_[EPS_FIR_LOCAL_ACTION1_08]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_08]

//>> SET_[EPS_FIR_LOCAL_ACTION1_09]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_09]

//>> SET_[EPS_FIR_LOCAL_ACTION1_09]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_09]

//>> SET_[EPS_FIR_LOCAL_ACTION1_09]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_09]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_09]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_09]

//>> GET_[EPS_FIR_LOCAL_ACTION1_09]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_09]

//>> GET_[EPS_FIR_LOCAL_ACTION1_09]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_09]

//>> SET_[EPS_FIR_LOCAL_ACTION1_10]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_10]

//>> SET_[EPS_FIR_LOCAL_ACTION1_10]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_10]

//>> SET_[EPS_FIR_LOCAL_ACTION1_10]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_10]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_10]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_10]

//>> GET_[EPS_FIR_LOCAL_ACTION1_10]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_10]

//>> GET_[EPS_FIR_LOCAL_ACTION1_10]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_10]

//>> SET_[EPS_FIR_LOCAL_ACTION1_11]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_11]

//>> SET_[EPS_FIR_LOCAL_ACTION1_11]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_11]

//>> SET_[EPS_FIR_LOCAL_ACTION1_11]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_11]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_11]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_11]

//>> GET_[EPS_FIR_LOCAL_ACTION1_11]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_11]

//>> GET_[EPS_FIR_LOCAL_ACTION1_11]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_11]

//>> SET_[EPS_FIR_LOCAL_ACTION1_12]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_12]

//>> SET_[EPS_FIR_LOCAL_ACTION1_12]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_12]

//>> SET_[EPS_FIR_LOCAL_ACTION1_12]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_12]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_12]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_12]

//>> GET_[EPS_FIR_LOCAL_ACTION1_12]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_12]

//>> GET_[EPS_FIR_LOCAL_ACTION1_12]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_12]

//>> SET_[EPS_FIR_LOCAL_ACTION1_13]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_13]

//>> SET_[EPS_FIR_LOCAL_ACTION1_13]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_13]

//>> SET_[EPS_FIR_LOCAL_ACTION1_13]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_13]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_13]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_13]

//>> GET_[EPS_FIR_LOCAL_ACTION1_13]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_13]

//>> GET_[EPS_FIR_LOCAL_ACTION1_13]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_13]

//>> SET_[EPS_FIR_LOCAL_ACTION1_14]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_14]

//>> SET_[EPS_FIR_LOCAL_ACTION1_14]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_14]

//>> SET_[EPS_FIR_LOCAL_ACTION1_14]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_14]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_14]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_14]

//>> GET_[EPS_FIR_LOCAL_ACTION1_14]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_14]

//>> GET_[EPS_FIR_LOCAL_ACTION1_14]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_14]

//>> SET_[EPS_FIR_LOCAL_ACTION1_15]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_15]

//>> SET_[EPS_FIR_LOCAL_ACTION1_15]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_15]

//>> SET_[EPS_FIR_LOCAL_ACTION1_15]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_15]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_15]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_15]

//>> GET_[EPS_FIR_LOCAL_ACTION1_15]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_15]

//>> GET_[EPS_FIR_LOCAL_ACTION1_15]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_15]

//>> SET_[EPS_FIR_LOCAL_ACTION1_16]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_16]

//>> SET_[EPS_FIR_LOCAL_ACTION1_16]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_16]

//>> SET_[EPS_FIR_LOCAL_ACTION1_16]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_16]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_16]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_16]

//>> GET_[EPS_FIR_LOCAL_ACTION1_16]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_16]

//>> GET_[EPS_FIR_LOCAL_ACTION1_16]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_16]

//>> SET_[EPS_FIR_LOCAL_ACTION1_17]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_17]

//>> SET_[EPS_FIR_LOCAL_ACTION1_17]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_17]

//>> SET_[EPS_FIR_LOCAL_ACTION1_17]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_17]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_17]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_17]

//>> GET_[EPS_FIR_LOCAL_ACTION1_17]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_17]

//>> GET_[EPS_FIR_LOCAL_ACTION1_17]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_17]

//>> SET_[EPS_FIR_LOCAL_ACTION1_18]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_18]

//>> SET_[EPS_FIR_LOCAL_ACTION1_18]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_18]

//>> SET_[EPS_FIR_LOCAL_ACTION1_18]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_18]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_18]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_18]

//>> GET_[EPS_FIR_LOCAL_ACTION1_18]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_18]

//>> GET_[EPS_FIR_LOCAL_ACTION1_18]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_18]

//>> SET_[EPS_FIR_LOCAL_ACTION1_19]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_19]

//>> SET_[EPS_FIR_LOCAL_ACTION1_19]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_19]

//>> SET_[EPS_FIR_LOCAL_ACTION1_19]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_19]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_19]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_19]

//>> GET_[EPS_FIR_LOCAL_ACTION1_19]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_19]

//>> GET_[EPS_FIR_LOCAL_ACTION1_19]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_19]

//>> SET_[EPS_FIR_LOCAL_ACTION1_20]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_20]

//>> SET_[EPS_FIR_LOCAL_ACTION1_20]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_20]

//>> SET_[EPS_FIR_LOCAL_ACTION1_20]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_20]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_20]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_20]

//>> GET_[EPS_FIR_LOCAL_ACTION1_20]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_20]

//>> GET_[EPS_FIR_LOCAL_ACTION1_20]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_20]

//>> SET_[EPS_FIR_LOCAL_ACTION1_21]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_21]

//>> SET_[EPS_FIR_LOCAL_ACTION1_21]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_21]

//>> SET_[EPS_FIR_LOCAL_ACTION1_21]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_21]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_21]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_21]

//>> GET_[EPS_FIR_LOCAL_ACTION1_21]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_21]

//>> GET_[EPS_FIR_LOCAL_ACTION1_21]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_21]

//>> SET_[EPS_FIR_LOCAL_ACTION1_22]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_22]

//>> SET_[EPS_FIR_LOCAL_ACTION1_22]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_22]

//>> SET_[EPS_FIR_LOCAL_ACTION1_22]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_22]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_22]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_22]

//>> GET_[EPS_FIR_LOCAL_ACTION1_22]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_22]

//>> GET_[EPS_FIR_LOCAL_ACTION1_22]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_22]

//>> SET_[EPS_FIR_LOCAL_ACTION1_23]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_23]

//>> SET_[EPS_FIR_LOCAL_ACTION1_23]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_23]

//>> SET_[EPS_FIR_LOCAL_ACTION1_23]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_23]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_23]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_23]

//>> GET_[EPS_FIR_LOCAL_ACTION1_23]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_23]

//>> GET_[EPS_FIR_LOCAL_ACTION1_23]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_23]

//>> SET_[EPS_FIR_LOCAL_ACTION1_24]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_24]

//>> SET_[EPS_FIR_LOCAL_ACTION1_24]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_24]

//>> SET_[EPS_FIR_LOCAL_ACTION1_24]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_24]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_24]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_24]

//>> GET_[EPS_FIR_LOCAL_ACTION1_24]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_24]

//>> GET_[EPS_FIR_LOCAL_ACTION1_24]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_24]

//>> SET_[EPS_FIR_LOCAL_ACTION1_25]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_25]

//>> SET_[EPS_FIR_LOCAL_ACTION1_25]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_25]

//>> SET_[EPS_FIR_LOCAL_ACTION1_25]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_25]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_25]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_25]

//>> GET_[EPS_FIR_LOCAL_ACTION1_25]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_25]

//>> GET_[EPS_FIR_LOCAL_ACTION1_25]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_25]

//>> SET_[EPS_FIR_LOCAL_ACTION1_26]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_26]

//>> SET_[EPS_FIR_LOCAL_ACTION1_26]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_26]

//>> SET_[EPS_FIR_LOCAL_ACTION1_26]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_26]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_26]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_26]

//>> GET_[EPS_FIR_LOCAL_ACTION1_26]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_26]

//>> GET_[EPS_FIR_LOCAL_ACTION1_26]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_26]

//>> SET_[EPS_FIR_LOCAL_ACTION1_27]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_27]

//>> SET_[EPS_FIR_LOCAL_ACTION1_27]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_27]

//>> SET_[EPS_FIR_LOCAL_ACTION1_27]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_27]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_27]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_27]

//>> GET_[EPS_FIR_LOCAL_ACTION1_27]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_27]

//>> GET_[EPS_FIR_LOCAL_ACTION1_27]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_27]

//>> SET_[EPS_FIR_LOCAL_ACTION1_28]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_28]

//>> SET_[EPS_FIR_LOCAL_ACTION1_28]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_28]

//>> SET_[EPS_FIR_LOCAL_ACTION1_28]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_28]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_28]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_28]

//>> GET_[EPS_FIR_LOCAL_ACTION1_28]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_28]

//>> GET_[EPS_FIR_LOCAL_ACTION1_28]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_28]

//>> SET_[EPS_FIR_LOCAL_ACTION1_29]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_29]

//>> SET_[EPS_FIR_LOCAL_ACTION1_29]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_29]

//>> SET_[EPS_FIR_LOCAL_ACTION1_29]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_29]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_29]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_29]

//>> GET_[EPS_FIR_LOCAL_ACTION1_29]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_29]

//>> GET_[EPS_FIR_LOCAL_ACTION1_29]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_29]

//>> SET_[EPS_FIR_LOCAL_ACTION1_30]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_30]

//>> SET_[EPS_FIR_LOCAL_ACTION1_30]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_30]

//>> SET_[EPS_FIR_LOCAL_ACTION1_30]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_30]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_30]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_30]

//>> GET_[EPS_FIR_LOCAL_ACTION1_30]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_30]

//>> GET_[EPS_FIR_LOCAL_ACTION1_30]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_30]

//>> SET_[EPS_FIR_LOCAL_ACTION1_31]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_31]

//>> SET_[EPS_FIR_LOCAL_ACTION1_31]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_31]

//>> SET_[EPS_FIR_LOCAL_ACTION1_31]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_31]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_31]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_31]

//>> GET_[EPS_FIR_LOCAL_ACTION1_31]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_31]

//>> GET_[EPS_FIR_LOCAL_ACTION1_31]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_31]

//>> SET_[EPS_FIR_LOCAL_ACTION1_32]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_32]

//>> SET_[EPS_FIR_LOCAL_ACTION1_32]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_32]

//>> SET_[EPS_FIR_LOCAL_ACTION1_32]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_32]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_32]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_32]

//>> GET_[EPS_FIR_LOCAL_ACTION1_32]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_32]

//>> GET_[EPS_FIR_LOCAL_ACTION1_32]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_32]

//>> SET_[EPS_FIR_LOCAL_ACTION1_33]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_33]

//>> SET_[EPS_FIR_LOCAL_ACTION1_33]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_33]

//>> SET_[EPS_FIR_LOCAL_ACTION1_33]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_33]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_33]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_33]

//>> GET_[EPS_FIR_LOCAL_ACTION1_33]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_33]

//>> GET_[EPS_FIR_LOCAL_ACTION1_33]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_33]

//>> SET_[EPS_FIR_LOCAL_ACTION1_34]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_34]

//>> SET_[EPS_FIR_LOCAL_ACTION1_34]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_34]

//>> SET_[EPS_FIR_LOCAL_ACTION1_34]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_34]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_34]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_34]

//>> GET_[EPS_FIR_LOCAL_ACTION1_34]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_34]

//>> GET_[EPS_FIR_LOCAL_ACTION1_34]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_34]

//>> SET_[EPS_FIR_LOCAL_ACTION1_35]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_35]

//>> SET_[EPS_FIR_LOCAL_ACTION1_35]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_35]

//>> SET_[EPS_FIR_LOCAL_ACTION1_35]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_35]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_35]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_35]

//>> GET_[EPS_FIR_LOCAL_ACTION1_35]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_35]

//>> GET_[EPS_FIR_LOCAL_ACTION1_35]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_35]

//>> SET_[EPS_FIR_LOCAL_ACTION1_36]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_36]

//>> SET_[EPS_FIR_LOCAL_ACTION1_36]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_36]

//>> SET_[EPS_FIR_LOCAL_ACTION1_36]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_36]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_36]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_36]

//>> GET_[EPS_FIR_LOCAL_ACTION1_36]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_36]

//>> GET_[EPS_FIR_LOCAL_ACTION1_36]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_36]

//>> SET_[EPS_FIR_LOCAL_ACTION1_37]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_37]

//>> SET_[EPS_FIR_LOCAL_ACTION1_37]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_37]

//>> SET_[EPS_FIR_LOCAL_ACTION1_37]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_37]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_37]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_37]

//>> GET_[EPS_FIR_LOCAL_ACTION1_37]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_37]

//>> GET_[EPS_FIR_LOCAL_ACTION1_37]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_37]

//>> SET_[EPS_FIR_LOCAL_ACTION1_38]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_38]

//>> SET_[EPS_FIR_LOCAL_ACTION1_38]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_38]

//>> SET_[EPS_FIR_LOCAL_ACTION1_38]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_38]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_38]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_38]

//>> GET_[EPS_FIR_LOCAL_ACTION1_38]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_38]

//>> GET_[EPS_FIR_LOCAL_ACTION1_38]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_38]

//>> SET_[EPS_FIR_LOCAL_ACTION1_39]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_39]

//>> SET_[EPS_FIR_LOCAL_ACTION1_39]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_39]

//>> SET_[EPS_FIR_LOCAL_ACTION1_39]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_39]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_39]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_39]

//>> GET_[EPS_FIR_LOCAL_ACTION1_39]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_39]

//>> GET_[EPS_FIR_LOCAL_ACTION1_39]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_39]

//>> SET_[EPS_FIR_LOCAL_ACTION1_40]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_40]

//>> SET_[EPS_FIR_LOCAL_ACTION1_40]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_40]

//>> SET_[EPS_FIR_LOCAL_ACTION1_40]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_40]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_40]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_40]

//>> GET_[EPS_FIR_LOCAL_ACTION1_40]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_40]

//>> GET_[EPS_FIR_LOCAL_ACTION1_40]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_40]

//>> SET_[EPS_FIR_LOCAL_ACTION1_41]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_41]

//>> SET_[EPS_FIR_LOCAL_ACTION1_41]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_41]

//>> SET_[EPS_FIR_LOCAL_ACTION1_41]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_41]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_41]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_41]

//>> GET_[EPS_FIR_LOCAL_ACTION1_41]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_41]

//>> GET_[EPS_FIR_LOCAL_ACTION1_41]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_41]

//>> SET_[EPS_FIR_LOCAL_ACTION1_42]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_42]

//>> SET_[EPS_FIR_LOCAL_ACTION1_42]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_42]

//>> SET_[EPS_FIR_LOCAL_ACTION1_42]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_42]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_42]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_42]

//>> GET_[EPS_FIR_LOCAL_ACTION1_42]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_42]

//>> GET_[EPS_FIR_LOCAL_ACTION1_42]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_42]

//>> SET_[EPS_FIR_LOCAL_ACTION1_43]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_43]

//>> SET_[EPS_FIR_LOCAL_ACTION1_43]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_43]

//>> SET_[EPS_FIR_LOCAL_ACTION1_43]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_43]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_43]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_43]

//>> GET_[EPS_FIR_LOCAL_ACTION1_43]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_43]

//>> GET_[EPS_FIR_LOCAL_ACTION1_43]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_43]

//>> SET_[EPS_FIR_LOCAL_ACTION1_44]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_44]

//>> SET_[EPS_FIR_LOCAL_ACTION1_44]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_44]

//>> SET_[EPS_FIR_LOCAL_ACTION1_44]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_44]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_44]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_44]

//>> GET_[EPS_FIR_LOCAL_ACTION1_44]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_44]

//>> GET_[EPS_FIR_LOCAL_ACTION1_44]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_44]

//>> SET_[EPS_FIR_LOCAL_ACTION1_45]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_45]

//>> SET_[EPS_FIR_LOCAL_ACTION1_45]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_45]

//>> SET_[EPS_FIR_LOCAL_ACTION1_45]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_45]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_45]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_45]

//>> GET_[EPS_FIR_LOCAL_ACTION1_45]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_45]

//>> GET_[EPS_FIR_LOCAL_ACTION1_45]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_45]

//>> SET_[EPS_FIR_LOCAL_ACTION1_46]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_46]

//>> SET_[EPS_FIR_LOCAL_ACTION1_46]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_46]

//>> SET_[EPS_FIR_LOCAL_ACTION1_46]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_46]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_46]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_46]

//>> GET_[EPS_FIR_LOCAL_ACTION1_46]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_46]

//>> GET_[EPS_FIR_LOCAL_ACTION1_46]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_46]

//>> SET_[EPS_FIR_LOCAL_ACTION1_47]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_47]

//>> SET_[EPS_FIR_LOCAL_ACTION1_47]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_47]

//>> SET_[EPS_FIR_LOCAL_ACTION1_47]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_47]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_47]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_47]

//>> GET_[EPS_FIR_LOCAL_ACTION1_47]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_47]

//>> GET_[EPS_FIR_LOCAL_ACTION1_47]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_47]

//>> SET_[EPS_FIR_LOCAL_ACTION1_48]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_48]

//>> SET_[EPS_FIR_LOCAL_ACTION1_48]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_48]

//>> SET_[EPS_FIR_LOCAL_ACTION1_48]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_48]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_48]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_48]

//>> GET_[EPS_FIR_LOCAL_ACTION1_48]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_48]

//>> GET_[EPS_FIR_LOCAL_ACTION1_48]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_48]

//>> SET_[EPS_FIR_LOCAL_ACTION1_49]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_49]

//>> SET_[EPS_FIR_LOCAL_ACTION1_49]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_49]

//>> SET_[EPS_FIR_LOCAL_ACTION1_49]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_49]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_49]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_49]

//>> GET_[EPS_FIR_LOCAL_ACTION1_49]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_49]

//>> GET_[EPS_FIR_LOCAL_ACTION1_49]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_49]

//>> SET_[EPS_FIR_LOCAL_ACTION1_50]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_50]

//>> SET_[EPS_FIR_LOCAL_ACTION1_50]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_50]

//>> SET_[EPS_FIR_LOCAL_ACTION1_50]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_50]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_50]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_50]

//>> GET_[EPS_FIR_LOCAL_ACTION1_50]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_50]

//>> GET_[EPS_FIR_LOCAL_ACTION1_50]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_50]

//>> SET_[EPS_FIR_LOCAL_ACTION1_51]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_51]

//>> SET_[EPS_FIR_LOCAL_ACTION1_51]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_51]

//>> SET_[EPS_FIR_LOCAL_ACTION1_51]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_51]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_51]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_51]

//>> GET_[EPS_FIR_LOCAL_ACTION1_51]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_51]

//>> GET_[EPS_FIR_LOCAL_ACTION1_51]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_51]

//>> SET_[EPS_FIR_LOCAL_ACTION1_52]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_52]

//>> SET_[EPS_FIR_LOCAL_ACTION1_52]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_52]

//>> SET_[EPS_FIR_LOCAL_ACTION1_52]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_52]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_52]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_52]

//>> GET_[EPS_FIR_LOCAL_ACTION1_52]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_52]

//>> GET_[EPS_FIR_LOCAL_ACTION1_52]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_52]

//>> SET_[EPS_FIR_LOCAL_ACTION1_53]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_53]

//>> SET_[EPS_FIR_LOCAL_ACTION1_53]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_53]

//>> SET_[EPS_FIR_LOCAL_ACTION1_53]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_53]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_53]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_53]

//>> GET_[EPS_FIR_LOCAL_ACTION1_53]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_53]

//>> GET_[EPS_FIR_LOCAL_ACTION1_53]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_53]

//>> SET_[EPS_FIR_LOCAL_ACTION1_54]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_54]

//>> SET_[EPS_FIR_LOCAL_ACTION1_54]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_54]

//>> SET_[EPS_FIR_LOCAL_ACTION1_54]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_54]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_54]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_54]

//>> GET_[EPS_FIR_LOCAL_ACTION1_54]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_54]

//>> GET_[EPS_FIR_LOCAL_ACTION1_54]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_54]

//>> SET_[EPS_FIR_LOCAL_ACTION1_55]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_55]

//>> SET_[EPS_FIR_LOCAL_ACTION1_55]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_55]

//>> SET_[EPS_FIR_LOCAL_ACTION1_55]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_55]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_55]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_55]

//>> GET_[EPS_FIR_LOCAL_ACTION1_55]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_55,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_55]

//>> GET_[EPS_FIR_LOCAL_ACTION1_55]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_55(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_55]

//>> SET_[EPS_FIR_LOCAL_ACTION1_56]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_56]

//>> SET_[EPS_FIR_LOCAL_ACTION1_56]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_56]

//>> SET_[EPS_FIR_LOCAL_ACTION1_56]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_56]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_56]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_56]

//>> GET_[EPS_FIR_LOCAL_ACTION1_56]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_56]

//>> GET_[EPS_FIR_LOCAL_ACTION1_56]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_56]

//>> SET_[EPS_FIR_LOCAL_ACTION1_57]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_57]

//>> SET_[EPS_FIR_LOCAL_ACTION1_57]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_57]

//>> SET_[EPS_FIR_LOCAL_ACTION1_57]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_57]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_57]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_57]

//>> GET_[EPS_FIR_LOCAL_ACTION1_57]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_57]

//>> GET_[EPS_FIR_LOCAL_ACTION1_57]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_57]

//>> SET_[EPS_FIR_LOCAL_ACTION1_58]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_58]

//>> SET_[EPS_FIR_LOCAL_ACTION1_58]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_58]

//>> SET_[EPS_FIR_LOCAL_ACTION1_58]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_58]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_58]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_58]

//>> GET_[EPS_FIR_LOCAL_ACTION1_58]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_58]

//>> GET_[EPS_FIR_LOCAL_ACTION1_58]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_58]

//>> SET_[EPS_FIR_LOCAL_ACTION1_59]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_59]

//>> SET_[EPS_FIR_LOCAL_ACTION1_59]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_59]

//>> SET_[EPS_FIR_LOCAL_ACTION1_59]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_59]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_59]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_59]

//>> GET_[EPS_FIR_LOCAL_ACTION1_59]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_59]

//>> GET_[EPS_FIR_LOCAL_ACTION1_59]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_59]

//>> SET_[EPS_FIR_LOCAL_ACTION1_60]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_60]

//>> SET_[EPS_FIR_LOCAL_ACTION1_60]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_60]

//>> SET_[EPS_FIR_LOCAL_ACTION1_60]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_60]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_60]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_60]

//>> GET_[EPS_FIR_LOCAL_ACTION1_60]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_60]

//>> GET_[EPS_FIR_LOCAL_ACTION1_60]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_60]

//>> SET_[EPS_FIR_LOCAL_ACTION1_61]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_61]

//>> SET_[EPS_FIR_LOCAL_ACTION1_61]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_61]

//>> SET_[EPS_FIR_LOCAL_ACTION1_61]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_61]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_61]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_61]

//>> GET_[EPS_FIR_LOCAL_ACTION1_61]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_61]

//>> GET_[EPS_FIR_LOCAL_ACTION1_61]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_61]

//>> SET_[EPS_FIR_LOCAL_ACTION1_62]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_62]

//>> SET_[EPS_FIR_LOCAL_ACTION1_62]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_62]

//>> SET_[EPS_FIR_LOCAL_ACTION1_62]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_62]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_62]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_62]

//>> GET_[EPS_FIR_LOCAL_ACTION1_62]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_62]

//>> GET_[EPS_FIR_LOCAL_ACTION1_62]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_62]

//>> SET_[EPS_FIR_LOCAL_ACTION1_63]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_63]

//>> SET_[EPS_FIR_LOCAL_ACTION1_63]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION1_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_63]

//>> SET_[EPS_FIR_LOCAL_ACTION1_63]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION1_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION1_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION1_63]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION1_63]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION1_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION1_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION1_63]

//>> GET_[EPS_FIR_LOCAL_ACTION1_63]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION1_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION1_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_63]

//>> GET_[EPS_FIR_LOCAL_ACTION1_63]
static inline bool GET_EPS_FIR_LOCAL_ACTION1_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION1_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access EPS_FIR_LOCAL_ACTION1_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION1_63]

//>> PREP_[OPCG_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OPCG_REG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_REG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[OPCG_REG1]

//>> GET_[OPCG_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OPCG_REG1(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_REG1;
#endif
    return fapi2::getScom(i_target, OPCG_REG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[OPCG_REG1]

//>> PUT_[OPCG_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OPCG_REG1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return fapi2::putScom(i_target, OPCG_REG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[OPCG_REG1]


//>> SET_[OPCG_REG1_SCAN_COUNT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_SCAN_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_SCAN_COUNT,
           OPCG_REG1_SCAN_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_REG1_SCAN_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_SCAN_COUNT]

//>> SET_[OPCG_REG1_SCAN_COUNT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_SCAN_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_SCAN_COUNT,
           OPCG_REG1_SCAN_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_REG1_SCAN_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_SCAN_COUNT]

//>> GET_[OPCG_REG1_SCAN_COUNT]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG1_SCAN_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.extractToRight<OPCG_REG1_SCAN_COUNT,
           OPCG_REG1_SCAN_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_REG1_SCAN_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_SCAN_COUNT]

//>> SET_[OPCG_REG1_MISR_A_VAL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_MISR_A_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_MISR_A_VAL,
           OPCG_REG1_MISR_A_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_REG1_MISR_A_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_MISR_A_VAL]

//>> SET_[OPCG_REG1_MISR_A_VAL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_MISR_A_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_MISR_A_VAL,
           OPCG_REG1_MISR_A_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_REG1_MISR_A_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_MISR_A_VAL]

//>> GET_[OPCG_REG1_MISR_A_VAL]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG1_MISR_A_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.extractToRight<OPCG_REG1_MISR_A_VAL,
           OPCG_REG1_MISR_A_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_REG1_MISR_A_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_MISR_A_VAL]

//>> SET_[OPCG_REG1_MISR_B_VAL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_MISR_B_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_MISR_B_VAL,
           OPCG_REG1_MISR_B_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_REG1_MISR_B_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_MISR_B_VAL]

//>> SET_[OPCG_REG1_MISR_B_VAL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_MISR_B_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_MISR_B_VAL,
           OPCG_REG1_MISR_B_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_REG1_MISR_B_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_MISR_B_VAL]

//>> GET_[OPCG_REG1_MISR_B_VAL]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG1_MISR_B_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.extractToRight<OPCG_REG1_MISR_B_VAL,
           OPCG_REG1_MISR_B_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_REG1_MISR_B_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_MISR_B_VAL]

//>> SET_[OPCG_REG1_MISR_INIT_WAIT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_MISR_INIT_WAIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_MISR_INIT_WAIT,
           OPCG_REG1_MISR_INIT_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_REG1_MISR_INIT_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_MISR_INIT_WAIT]

//>> SET_[OPCG_REG1_MISR_INIT_WAIT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_MISR_INIT_WAIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_MISR_INIT_WAIT,
           OPCG_REG1_MISR_INIT_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_REG1_MISR_INIT_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_MISR_INIT_WAIT]

//>> GET_[OPCG_REG1_MISR_INIT_WAIT]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG1_MISR_INIT_WAIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.extractToRight<OPCG_REG1_MISR_INIT_WAIT,
           OPCG_REG1_MISR_INIT_WAIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_REG1_MISR_INIT_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_MISR_INIT_WAIT]

//>> SET_[OPCG_REG1_SCAN_CLK_USE_EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_SCAN_CLK_USE_EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_SCAN_CLK_USE_EVEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_REG1_SCAN_CLK_USE_EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_SCAN_CLK_USE_EVEN]

//>> SET_[OPCG_REG1_SCAN_CLK_USE_EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_SCAN_CLK_USE_EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_SCAN_CLK_USE_EVEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_REG1_SCAN_CLK_USE_EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_SCAN_CLK_USE_EVEN]

//>> SET_[OPCG_REG1_SCAN_CLK_USE_EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_SCAN_CLK_USE_EVEN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.setBit<OPCG_REG1_SCAN_CLK_USE_EVEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access OPCG_REG1_SCAN_CLK_USE_EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_SCAN_CLK_USE_EVEN]

//>> CLEAR_[OPCG_REG1_SCAN_CLK_USE_EVEN]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG1_SCAN_CLK_USE_EVEN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.clearBit<OPCG_REG1_SCAN_CLK_USE_EVEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access OPCG_REG1_SCAN_CLK_USE_EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG1_SCAN_CLK_USE_EVEN]

//>> GET_[OPCG_REG1_SCAN_CLK_USE_EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG1_SCAN_CLK_USE_EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.extractToRight<OPCG_REG1_SCAN_CLK_USE_EVEN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_REG1_SCAN_CLK_USE_EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_SCAN_CLK_USE_EVEN]

//>> GET_[OPCG_REG1_SCAN_CLK_USE_EVEN]
static inline bool GET_OPCG_REG1_SCAN_CLK_USE_EVEN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.getBit<OPCG_REG1_SCAN_CLK_USE_EVEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access OPCG_REG1_SCAN_CLK_USE_EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_SCAN_CLK_USE_EVEN]

//>> SET_[OPCG_REG1_DISABLE_FCE_DURING_FILL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_DISABLE_FCE_DURING_FILL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_DISABLE_FCE_DURING_FILL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_REG1_DISABLE_FCE_DURING_FILL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_DISABLE_FCE_DURING_FILL]

//>> SET_[OPCG_REG1_DISABLE_FCE_DURING_FILL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_DISABLE_FCE_DURING_FILL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_DISABLE_FCE_DURING_FILL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_REG1_DISABLE_FCE_DURING_FILL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_DISABLE_FCE_DURING_FILL]

//>> SET_[OPCG_REG1_DISABLE_FCE_DURING_FILL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_DISABLE_FCE_DURING_FILL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.setBit<OPCG_REG1_DISABLE_FCE_DURING_FILL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access OPCG_REG1_DISABLE_FCE_DURING_FILL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_DISABLE_FCE_DURING_FILL]

//>> CLEAR_[OPCG_REG1_DISABLE_FCE_DURING_FILL]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG1_DISABLE_FCE_DURING_FILL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.clearBit<OPCG_REG1_DISABLE_FCE_DURING_FILL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access OPCG_REG1_DISABLE_FCE_DURING_FILL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG1_DISABLE_FCE_DURING_FILL]

//>> GET_[OPCG_REG1_DISABLE_FCE_DURING_FILL]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG1_DISABLE_FCE_DURING_FILL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.extractToRight<OPCG_REG1_DISABLE_FCE_DURING_FILL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_REG1_DISABLE_FCE_DURING_FILL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_DISABLE_FCE_DURING_FILL]

//>> GET_[OPCG_REG1_DISABLE_FCE_DURING_FILL]
static inline bool GET_OPCG_REG1_DISABLE_FCE_DURING_FILL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.getBit<OPCG_REG1_DISABLE_FCE_DURING_FILL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access OPCG_REG1_DISABLE_FCE_DURING_FILL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_DISABLE_FCE_DURING_FILL]

//>> SET_[OPCG_REG1_RTIM_THOLD_FORCE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_RTIM_THOLD_FORCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_RTIM_THOLD_FORCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_REG1_RTIM_THOLD_FORCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_RTIM_THOLD_FORCE]

//>> SET_[OPCG_REG1_RTIM_THOLD_FORCE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_RTIM_THOLD_FORCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_RTIM_THOLD_FORCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_REG1_RTIM_THOLD_FORCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_RTIM_THOLD_FORCE]

//>> SET_[OPCG_REG1_RTIM_THOLD_FORCE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_RTIM_THOLD_FORCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.setBit<OPCG_REG1_RTIM_THOLD_FORCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access OPCG_REG1_RTIM_THOLD_FORCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_RTIM_THOLD_FORCE]

//>> CLEAR_[OPCG_REG1_RTIM_THOLD_FORCE]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG1_RTIM_THOLD_FORCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.clearBit<OPCG_REG1_RTIM_THOLD_FORCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access OPCG_REG1_RTIM_THOLD_FORCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG1_RTIM_THOLD_FORCE]

//>> GET_[OPCG_REG1_RTIM_THOLD_FORCE]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG1_RTIM_THOLD_FORCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.extractToRight<OPCG_REG1_RTIM_THOLD_FORCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_REG1_RTIM_THOLD_FORCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_RTIM_THOLD_FORCE]

//>> GET_[OPCG_REG1_RTIM_THOLD_FORCE]
static inline bool GET_OPCG_REG1_RTIM_THOLD_FORCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.getBit<OPCG_REG1_RTIM_THOLD_FORCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access OPCG_REG1_RTIM_THOLD_FORCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_RTIM_THOLD_FORCE]

//>> SET_[OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL]

//>> SET_[OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL]

//>> SET_[OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.setBit<OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL]

//>> CLEAR_[OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.clearBit<OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL]

//>> GET_[OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.extractToRight<OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL]

//>> GET_[OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL]
static inline bool GET_OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.getBit<OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL]

//>> SET_[OPCG_REG1_SG_HIGH_DURING_FILL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_SG_HIGH_DURING_FILL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_SG_HIGH_DURING_FILL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_REG1_SG_HIGH_DURING_FILL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_SG_HIGH_DURING_FILL]

//>> SET_[OPCG_REG1_SG_HIGH_DURING_FILL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_SG_HIGH_DURING_FILL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_SG_HIGH_DURING_FILL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_REG1_SG_HIGH_DURING_FILL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_SG_HIGH_DURING_FILL]

//>> SET_[OPCG_REG1_SG_HIGH_DURING_FILL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_SG_HIGH_DURING_FILL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.setBit<OPCG_REG1_SG_HIGH_DURING_FILL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access OPCG_REG1_SG_HIGH_DURING_FILL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_SG_HIGH_DURING_FILL]

//>> CLEAR_[OPCG_REG1_SG_HIGH_DURING_FILL]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG1_SG_HIGH_DURING_FILL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.clearBit<OPCG_REG1_SG_HIGH_DURING_FILL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access OPCG_REG1_SG_HIGH_DURING_FILL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG1_SG_HIGH_DURING_FILL]

//>> GET_[OPCG_REG1_SG_HIGH_DURING_FILL]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG1_SG_HIGH_DURING_FILL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.extractToRight<OPCG_REG1_SG_HIGH_DURING_FILL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_REG1_SG_HIGH_DURING_FILL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_SG_HIGH_DURING_FILL]

//>> GET_[OPCG_REG1_SG_HIGH_DURING_FILL]
static inline bool GET_OPCG_REG1_SG_HIGH_DURING_FILL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.getBit<OPCG_REG1_SG_HIGH_DURING_FILL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access OPCG_REG1_SG_HIGH_DURING_FILL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_SG_HIGH_DURING_FILL]

//>> SET_[OPCG_REG1_LBIST_SKITTER_CTL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_LBIST_SKITTER_CTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_LBIST_SKITTER_CTL,
           OPCG_REG1_LBIST_SKITTER_CTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_REG1_LBIST_SKITTER_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_LBIST_SKITTER_CTL]

//>> SET_[OPCG_REG1_LBIST_SKITTER_CTL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_LBIST_SKITTER_CTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_LBIST_SKITTER_CTL,
           OPCG_REG1_LBIST_SKITTER_CTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_REG1_LBIST_SKITTER_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_LBIST_SKITTER_CTL]

//>> GET_[OPCG_REG1_LBIST_SKITTER_CTL]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG1_LBIST_SKITTER_CTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.extractToRight<OPCG_REG1_LBIST_SKITTER_CTL,
           OPCG_REG1_LBIST_SKITTER_CTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_REG1_LBIST_SKITTER_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_LBIST_SKITTER_CTL]

//>> SET_[OPCG_REG1_MISR_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_MISR_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_MISR_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_REG1_MISR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_MISR_MODE]

//>> SET_[OPCG_REG1_MISR_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_MISR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_MISR_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_REG1_MISR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_MISR_MODE]

//>> SET_[OPCG_REG1_MISR_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_MISR_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.setBit<OPCG_REG1_MISR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access OPCG_REG1_MISR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_MISR_MODE]

//>> CLEAR_[OPCG_REG1_MISR_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG1_MISR_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.clearBit<OPCG_REG1_MISR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access OPCG_REG1_MISR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG1_MISR_MODE]

//>> GET_[OPCG_REG1_MISR_MODE]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG1_MISR_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.extractToRight<OPCG_REG1_MISR_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_REG1_MISR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_MISR_MODE]

//>> GET_[OPCG_REG1_MISR_MODE]
static inline bool GET_OPCG_REG1_MISR_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.getBit<OPCG_REG1_MISR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access OPCG_REG1_MISR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_MISR_MODE]

//>> SET_[OPCG_REG1_INFINITE_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_INFINITE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_INFINITE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_REG1_INFINITE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_INFINITE_MODE]

//>> SET_[OPCG_REG1_INFINITE_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_INFINITE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_INFINITE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_REG1_INFINITE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_INFINITE_MODE]

//>> SET_[OPCG_REG1_INFINITE_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_INFINITE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.setBit<OPCG_REG1_INFINITE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access OPCG_REG1_INFINITE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_INFINITE_MODE]

//>> CLEAR_[OPCG_REG1_INFINITE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG1_INFINITE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.clearBit<OPCG_REG1_INFINITE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access OPCG_REG1_INFINITE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG1_INFINITE_MODE]

//>> GET_[OPCG_REG1_INFINITE_MODE]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG1_INFINITE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.extractToRight<OPCG_REG1_INFINITE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_REG1_INFINITE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_INFINITE_MODE]

//>> GET_[OPCG_REG1_INFINITE_MODE]
static inline bool GET_OPCG_REG1_INFINITE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.getBit<OPCG_REG1_INFINITE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access OPCG_REG1_INFINITE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_INFINITE_MODE]

//>> SET_[OPCG_REG1_NSL_FILL_COUNT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_NSL_FILL_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_NSL_FILL_COUNT,
           OPCG_REG1_NSL_FILL_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access OPCG_REG1_NSL_FILL_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_NSL_FILL_COUNT]

//>> SET_[OPCG_REG1_NSL_FILL_COUNT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG1_NSL_FILL_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return o_data.insertFromRight<OPCG_REG1_NSL_FILL_COUNT,
           OPCG_REG1_NSL_FILL_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access OPCG_REG1_NSL_FILL_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG1_NSL_FILL_COUNT]

//>> GET_[OPCG_REG1_NSL_FILL_COUNT]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG1_NSL_FILL_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG1));
#endif
    return i_data.extractToRight<OPCG_REG1_NSL_FILL_COUNT,
           OPCG_REG1_NSL_FILL_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access OPCG_REG1_NSL_FILL_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG1_NSL_FILL_COUNT]

//>> PREP_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PBCQ_PEPBREGS_PBCQHWCFG_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PBCQ_PEPBREGS_PBCQHWCFG_REG;
#endif
    return fapi2::getScom(i_target, PB_PBCQ_PEPBREGS_PBCQHWCFG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG]

//>> PUT_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return fapi2::putScom(i_target, PB_PBCQ_PEPBREGS_PBCQHWCFG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG]


//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_POLL_SCALE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_DATA_SCALE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_HANG_PE_SCALE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_BLOCK_CQPB_PB_INIT]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_SEQ_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_RCMD_CLKGATE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_HANG_SM_ON_ARE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_PCI_CLK_CHECK]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_LFSR_ARB_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAR_IOPACING]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_DMAW_IOPACING]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ADR_BAR_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_STQ_ALLOCATION]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_DISABLE_LPC_CMDS]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_OOO_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_OSMB_EARLY_START]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_QFIFO_HOLD_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED1]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_RD]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED4]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_STRICT_ORDER_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_CHANNEL_STREAMING_EN]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_WR_CACHE_INJECT_MODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_P2P_FORCE_DMA]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INJ_ON_RESEND]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_FORCE_DISABLED_CTAG_TO_FOLLOW_FLOW]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_ENH_FLOW]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RESERVED2]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_VG]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_WR_SCOPE_GROUP]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_VG]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_GROUP]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_INTWR_SCOPE_NODE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE,
           PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_INJECT_THRESHOLD_DEC_RATE]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_RD_WR_ORDERING]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_NODAL]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_GROUP]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_SCOPE_RNNN]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_RD_SKIP_GROUP]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_RD_VG]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_NODAL]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_GROUP]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_SCOPE_RNNN]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_ENABLE_TCE_SKIP_GROUP]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_VG]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_TCE_ARBITRATION]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_CQ_TCE_ARBITRATION]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_DISABLE_MC_PREFETCH]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT]

//>> SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.setBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT]

//>> CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return o_data.clearBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT]

//>> GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT]
static inline bool GET_PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PBCQHWCFG_REG));
#endif
    return i_data.getBit<PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PBCQHWCFG_REG_PE_IGNORE_SFSTAT]

//>> PREP_[PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2]

//>> GET_[PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2;
#endif
    return fapi2::getScom(i_target, PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2]

//>> PUT_[PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2));
#endif
    return fapi2::putScom(i_target, PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2]


//>> SET_[PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2,
           PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2]

//>> SET_[PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2]
static inline fapi2::buffer<uint64_t>& SET_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2));
#endif
    return o_data.insertFromRight<PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2,
           PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2]

//>> GET_[PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2]
static inline fapi2::buffer<uint64_t>& GET_PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2));
#endif
    return i_data.extractToRight<PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2,
           PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG2_PE_TOPOLOGY_ID_REG2]

//>> PREP_[SLAVE_CONFIG_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SLAVE_CONFIG_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SLAVE_CONFIG_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SLAVE_CONFIG_REG]

//>> GET_[SLAVE_CONFIG_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SLAVE_CONFIG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SLAVE_CONFIG_REG;
#endif
    return fapi2::getScom(i_target, SLAVE_CONFIG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SLAVE_CONFIG_REG]

//>> PUT_[SLAVE_CONFIG_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SLAVE_CONFIG_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return fapi2::putScom(i_target, SLAVE_CONFIG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SLAVE_CONFIG_REG]


//>> SET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]

//>> CLEAR_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]
static inline bool GET_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]

//>> SET_[SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]

//>> SET_[SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]

//>> SET_[SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]

//>> CLEAR_[SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]

//>> GET_[SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]

//>> GET_[SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]
static inline bool GET_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]

//>> CLEAR_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]
static inline bool GET_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]

//>> SET_[SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]

//>> SET_[SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]

//>> SET_[SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]

//>> CLEAR_[SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]

//>> GET_[SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]

//>> GET_[SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]
static inline bool GET_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]

//>> SET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]

//>> SET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]

//>> SET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]

//>> CLEAR_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]

//>> GET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]

//>> GET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]
static inline bool GET_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]

//>> SET_[SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]

//>> SET_[SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]

//>> SET_[SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]

//>> CLEAR_[SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]

//>> GET_[SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]

//>> GET_[SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]
static inline bool GET_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]

//>> CLEAR_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]
static inline bool GET_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]

//>> SET_[SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]

//>> SET_[SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]

//>> SET_[SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]

//>> CLEAR_[SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]

//>> GET_[SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]

//>> GET_[SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]
static inline bool GET_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_HEARTBEAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_HEARTBEAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_DISABLE_HEARTBEAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]

//>> CLEAR_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_DISABLE_HEARTBEAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_DISABLE_HEARTBEAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]
static inline bool GET_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_DISABLE_HEARTBEAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]

//>> SET_[SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]

//>> SET_[SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]

//>> SET_[SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]

//>> CLEAR_[SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]

//>> GET_[SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]

//>> GET_[SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]
static inline bool GET_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]

//>> CLEAR_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]
static inline bool GET_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]

//>> SET_[SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]

//>> SET_[SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]

//>> SET_[SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]

//>> CLEAR_[SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]

//>> GET_[SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]

//>> GET_[SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]
static inline bool GET_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]

//>> SET_[SLAVE_CONFIG_REG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_PM_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_PM_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_PM_DISABLE]

//>> SET_[SLAVE_CONFIG_REG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_PM_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_PM_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_PM_DISABLE]

//>> SET_[SLAVE_CONFIG_REG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_PM_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_PM_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_PM_DISABLE]

//>> CLEAR_[SLAVE_CONFIG_REG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_PM_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_PM_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_PM_DISABLE]

//>> GET_[SLAVE_CONFIG_REG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_PM_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_PM_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_PM_DISABLE]

//>> GET_[SLAVE_CONFIG_REG_PM_DISABLE]
static inline bool GET_SLAVE_CONFIG_REG_PM_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_PM_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_PM_DISABLE]

//>> SET_[SLAVE_CONFIG_REG_CFG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_PM_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_PM_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_PM_DISABLE]

//>> SET_[SLAVE_CONFIG_REG_CFG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_PM_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_PM_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_PM_DISABLE]

//>> SET_[SLAVE_CONFIG_REG_CFG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_PM_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_CFG_PM_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_PM_DISABLE]

//>> CLEAR_[SLAVE_CONFIG_REG_CFG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_CFG_PM_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_CFG_PM_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_CFG_PM_DISABLE]

//>> GET_[SLAVE_CONFIG_REG_CFG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_CFG_PM_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_CFG_PM_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_PM_DISABLE]

//>> GET_[SLAVE_CONFIG_REG_CFG_PM_DISABLE]
static inline bool GET_SLAVE_CONFIG_REG_CFG_PM_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_CFG_PM_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_PM_DISABLE]

//>> SET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_PM_MUX_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]

//>> SET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_PM_MUX_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_PM_MUX_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]

//>> SET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_PM_MUX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]

//>> CLEAR_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_PM_MUX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]

//>> GET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_PM_MUX_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]

//>> GET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]
static inline bool GET_SLAVE_CONFIG_REG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_PM_MUX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]

//>> SET_[SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]

//>> SET_[SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]

//>> SET_[SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]

//>> CLEAR_[SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]

//>> GET_[SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]

//>> GET_[SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]
static inline bool GET_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]

//>> SET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]

//>> CLEAR_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]

//>> GET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]

//>> GET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]
static inline bool GET_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]

//>> SET_[SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]

//>> SET_[SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]

//>> SET_[SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]

//>> CLEAR_[SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]

//>> GET_[SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]

//>> GET_[SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]
static inline bool GET_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]

//>> CLEAR_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]

//>> GET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]

//>> GET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]
static inline bool GET_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]

//>> SET_[SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]

//>> SET_[SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]

//>> SET_[SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]

//>> CLEAR_[SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]

//>> GET_[SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]

//>> GET_[SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]
static inline bool GET_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]

//>> CLEAR_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]

//>> GET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]

//>> GET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]
static inline bool GET_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]

//>> SET_[SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]

//>> SET_[SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]

//>> SET_[SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]

//>> CLEAR_[SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]

//>> GET_[SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]

//>> GET_[SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]
static inline bool GET_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_PCBSL_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_PCBSL_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_MASK_PCBSL_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]

//>> CLEAR_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_MASK_PCBSL_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]

//>> GET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_MASK_PCBSL_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]

//>> GET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]
static inline bool GET_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_MASK_PCBSL_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]

//>> SET_[SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]

//>> SET_[SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]

//>> SET_[SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]

//>> CLEAR_[SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]

//>> GET_[SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]

//>> GET_[SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]
static inline bool GET_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_PLL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PLL_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_PLL_ERRS,
           SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_PLL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_PLL_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_PLL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PLL_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_PLL_ERRS,
           SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_PLL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_PLL_ERRS]

//>> GET_[SLAVE_CONFIG_REG_MASK_PLL_ERRS]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_MASK_PLL_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_MASK_PLL_ERRS,
           SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_PLL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_PLL_ERRS]

//>> SET_[SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS,
           SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS]

//>> SET_[SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS,
           SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS]

//>> GET_[SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS,
           SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS]

//>> SET_[SLAVE_CONFIG_REG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_QME_PAR_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_QME_PAR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_QME_PAR_DIS]

//>> SET_[SLAVE_CONFIG_REG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_QME_PAR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_QME_PAR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_QME_PAR_DIS]

//>> SET_[SLAVE_CONFIG_REG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_QME_PAR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_QME_PAR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_QME_PAR_DIS]

//>> CLEAR_[SLAVE_CONFIG_REG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_QME_PAR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_QME_PAR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_QME_PAR_DIS]

//>> GET_[SLAVE_CONFIG_REG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_QME_PAR_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_QME_PAR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_QME_PAR_DIS]

//>> GET_[SLAVE_CONFIG_REG_QME_PAR_DIS]
static inline bool GET_SLAVE_CONFIG_REG_QME_PAR_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_QME_PAR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_QME_PAR_DIS]

//>> SET_[SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_QME_PAR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]

//>> SET_[SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_QME_PAR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]

//>> SET_[SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_CFG_QME_PAR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]

//>> CLEAR_[SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_CFG_QME_PAR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]

//>> GET_[SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_CFG_QME_PAR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]

//>> GET_[SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]
static inline bool GET_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_CFG_QME_PAR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]

//>> SET_[SLAVE_CONFIG_REG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_FORCE_0_QME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_FORCE_0_QME,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_FORCE_0_QME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_FORCE_0_QME]

//>> SET_[SLAVE_CONFIG_REG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_FORCE_0_QME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_FORCE_0_QME,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_FORCE_0_QME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_FORCE_0_QME]

//>> SET_[SLAVE_CONFIG_REG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_FORCE_0_QME(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_FORCE_0_QME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_FORCE_0_QME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_FORCE_0_QME]

//>> CLEAR_[SLAVE_CONFIG_REG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_FORCE_0_QME(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_FORCE_0_QME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_FORCE_0_QME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_FORCE_0_QME]

//>> GET_[SLAVE_CONFIG_REG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_FORCE_0_QME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_FORCE_0_QME,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_FORCE_0_QME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_FORCE_0_QME]

//>> GET_[SLAVE_CONFIG_REG_FORCE_0_QME]
static inline bool GET_SLAVE_CONFIG_REG_FORCE_0_QME(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_FORCE_0_QME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_FORCE_0_QME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_FORCE_0_QME]

//>> SET_[SLAVE_CONFIG_REG_CFG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_FORCE_0_QME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_FORCE_0_QME,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_FORCE_0_QME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_FORCE_0_QME]

//>> SET_[SLAVE_CONFIG_REG_CFG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_FORCE_0_QME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_CFG_FORCE_0_QME,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_FORCE_0_QME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_FORCE_0_QME]

//>> SET_[SLAVE_CONFIG_REG_CFG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_CFG_FORCE_0_QME(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_CFG_FORCE_0_QME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_FORCE_0_QME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_CFG_FORCE_0_QME]

//>> CLEAR_[SLAVE_CONFIG_REG_CFG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_CFG_FORCE_0_QME(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_CFG_FORCE_0_QME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_FORCE_0_QME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_CFG_FORCE_0_QME]

//>> GET_[SLAVE_CONFIG_REG_CFG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_CFG_FORCE_0_QME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_CFG_FORCE_0_QME,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_FORCE_0_QME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_FORCE_0_QME]

//>> GET_[SLAVE_CONFIG_REG_CFG_FORCE_0_QME]
static inline bool GET_SLAVE_CONFIG_REG_CFG_FORCE_0_QME(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_CFG_FORCE_0_QME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_CFG_FORCE_0_QME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_CFG_FORCE_0_QME]

//>> SET_[SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> CLEAR_[SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> GET_[SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> GET_[SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline bool GET_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> CLEAR_[SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> GET_[SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> GET_[SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline bool GET_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> PREP_[XSTOP2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XSTOP2]

//>> GET_[XSTOP2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP2(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP2;
#endif
    return fapi2::getScom(i_target, XSTOP2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XSTOP2]

//>> PUT_[XSTOP2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return fapi2::putScom(i_target, XSTOP2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XSTOP2]


//>> SET_[XSTOP2_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_ENABLE]

//>> SET_[XSTOP2_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_ENABLE]

//>> SET_[XSTOP2_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_ENABLE]

//>> CLEAR_[XSTOP2_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_ENABLE]

//>> GET_[XSTOP2_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_ENABLE]

//>> GET_[XSTOP2_ENABLE]
static inline bool GET_XSTOP2_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_ENABLE]

//>> SET_[XSTOP2_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_WAIT_SNOPA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_WAIT_SNOPA]

//>> SET_[XSTOP2_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_WAIT_SNOPA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_WAIT_SNOPA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_WAIT_SNOPA]

//>> SET_[XSTOP2_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_WAIT_SNOPA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_WAIT_SNOPA]

//>> CLEAR_[XSTOP2_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_WAIT_SNOPA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_WAIT_SNOPA]

//>> GET_[XSTOP2_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_WAIT_SNOPA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_WAIT_SNOPA]

//>> GET_[XSTOP2_WAIT_SNOPA]
static inline bool GET_XSTOP2_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_WAIT_SNOPA]

//>> SET_[XSTOP2_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_TRIGGER_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_TRIGGER_OPCG_GO]

//>> SET_[XSTOP2_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_TRIGGER_OPCG_GO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_TRIGGER_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_TRIGGER_OPCG_GO]

//>> SET_[XSTOP2_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_TRIGGER_OPCG_GO]

//>> CLEAR_[XSTOP2_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_TRIGGER_OPCG_GO]

//>> GET_[XSTOP2_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_TRIGGER_OPCG_GO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_TRIGGER_OPCG_GO]

//>> GET_[XSTOP2_TRIGGER_OPCG_GO]
static inline bool GET_XSTOP2_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_TRIGGER_OPCG_GO]

//>> SET_[XSTOP2_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_WAIT_ALWAYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_WAIT_ALWAYS]

//>> SET_[XSTOP2_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_WAIT_ALWAYS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_WAIT_ALWAYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_WAIT_ALWAYS]

//>> SET_[XSTOP2_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_WAIT_ALWAYS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_WAIT_ALWAYS]

//>> CLEAR_[XSTOP2_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_WAIT_ALWAYS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_WAIT_ALWAYS]

//>> GET_[XSTOP2_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_WAIT_ALWAYS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_WAIT_ALWAYS]

//>> GET_[XSTOP2_WAIT_ALWAYS]
static inline bool GET_XSTOP2_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_WAIT_ALWAYS]

//>> SET_[XSTOP2_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_PERV]

//>> SET_[XSTOP2_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_PERV]

//>> SET_[XSTOP2_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_PERV]

//>> CLEAR_[XSTOP2_REGION_PERV]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_PERV]

//>> GET_[XSTOP2_REGION_PERV]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_PERV]

//>> GET_[XSTOP2_REGION_PERV]
static inline bool GET_XSTOP2_REGION_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_PERV]

//>> SET_[XSTOP2_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT1]

//>> SET_[XSTOP2_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT1]

//>> SET_[XSTOP2_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT1]

//>> CLEAR_[XSTOP2_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT1]

//>> GET_[XSTOP2_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT1]

//>> GET_[XSTOP2_REGION_UNIT1]
static inline bool GET_XSTOP2_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT1]

//>> SET_[XSTOP2_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT2]

//>> SET_[XSTOP2_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT2]

//>> SET_[XSTOP2_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT2]

//>> CLEAR_[XSTOP2_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT2]

//>> GET_[XSTOP2_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT2]

//>> GET_[XSTOP2_REGION_UNIT2]
static inline bool GET_XSTOP2_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT2]

//>> SET_[XSTOP2_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT3]

//>> SET_[XSTOP2_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT3]

//>> SET_[XSTOP2_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT3]

//>> CLEAR_[XSTOP2_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT3]

//>> GET_[XSTOP2_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT3]

//>> GET_[XSTOP2_REGION_UNIT3]
static inline bool GET_XSTOP2_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT3]

//>> SET_[XSTOP2_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT4]

//>> SET_[XSTOP2_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT4]

//>> SET_[XSTOP2_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT4]

//>> CLEAR_[XSTOP2_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT4]

//>> GET_[XSTOP2_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT4]

//>> GET_[XSTOP2_REGION_UNIT4]
static inline bool GET_XSTOP2_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT4]

//>> SET_[XSTOP2_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT5]

//>> SET_[XSTOP2_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT5]

//>> SET_[XSTOP2_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT5]

//>> CLEAR_[XSTOP2_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT5]

//>> GET_[XSTOP2_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT5]

//>> GET_[XSTOP2_REGION_UNIT5]
static inline bool GET_XSTOP2_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT5]

//>> SET_[XSTOP2_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT6]

//>> SET_[XSTOP2_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT6]

//>> SET_[XSTOP2_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT6]

//>> CLEAR_[XSTOP2_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT6]

//>> GET_[XSTOP2_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT6]

//>> GET_[XSTOP2_REGION_UNIT6]
static inline bool GET_XSTOP2_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT6]

//>> SET_[XSTOP2_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT7]

//>> SET_[XSTOP2_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT7]

//>> SET_[XSTOP2_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT7]

//>> CLEAR_[XSTOP2_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT7]

//>> GET_[XSTOP2_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT7]

//>> GET_[XSTOP2_REGION_UNIT7]
static inline bool GET_XSTOP2_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT7]

//>> SET_[XSTOP2_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT8]

//>> SET_[XSTOP2_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT8]

//>> SET_[XSTOP2_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT8]

//>> CLEAR_[XSTOP2_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT8]

//>> GET_[XSTOP2_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT8]

//>> GET_[XSTOP2_REGION_UNIT8]
static inline bool GET_XSTOP2_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT8]

//>> SET_[XSTOP2_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT9]

//>> SET_[XSTOP2_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT9]

//>> SET_[XSTOP2_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT9]

//>> CLEAR_[XSTOP2_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT9]

//>> GET_[XSTOP2_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT9]

//>> GET_[XSTOP2_REGION_UNIT9]
static inline bool GET_XSTOP2_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT9]

//>> SET_[XSTOP2_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT10]

//>> SET_[XSTOP2_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT10]

//>> SET_[XSTOP2_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT10]

//>> CLEAR_[XSTOP2_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT10]

//>> GET_[XSTOP2_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT10]

//>> GET_[XSTOP2_REGION_UNIT10]
static inline bool GET_XSTOP2_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT10]

//>> SET_[XSTOP2_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT11]

//>> SET_[XSTOP2_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT11]

//>> SET_[XSTOP2_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT11]

//>> CLEAR_[XSTOP2_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT11]

//>> GET_[XSTOP2_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT11]

//>> GET_[XSTOP2_REGION_UNIT11]
static inline bool GET_XSTOP2_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT11]

//>> SET_[XSTOP2_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT12]

//>> SET_[XSTOP2_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT12]

//>> SET_[XSTOP2_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT12]

//>> CLEAR_[XSTOP2_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT12]

//>> GET_[XSTOP2_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT12]

//>> GET_[XSTOP2_REGION_UNIT12]
static inline bool GET_XSTOP2_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT12]

//>> SET_[XSTOP2_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT13]

//>> SET_[XSTOP2_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT13]

//>> SET_[XSTOP2_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT13]

//>> CLEAR_[XSTOP2_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT13]

//>> GET_[XSTOP2_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT13]

//>> GET_[XSTOP2_REGION_UNIT13]
static inline bool GET_XSTOP2_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT13]

//>> SET_[XSTOP2_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT14]

//>> SET_[XSTOP2_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT14]

//>> SET_[XSTOP2_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pec Invalid dial access XSTOP2_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT14]

//>> CLEAR_[XSTOP2_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pec Invalid dial access XSTOP2_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT14]

//>> GET_[XSTOP2_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT14]

//>> GET_[XSTOP2_REGION_UNIT14]
static inline bool GET_XSTOP2_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pec Invalid dial access XSTOP2_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT14]

//>> SET_[XSTOP2_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_WAIT_CYCLES,
           XSTOP2_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pec Invalid dial access XSTOP2_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_WAIT_CYCLES]

//>> SET_[XSTOP2_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_WAIT_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_WAIT_CYCLES,
           XSTOP2_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pec Invalid dial access XSTOP2_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_WAIT_CYCLES]

//>> GET_[XSTOP2_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_WAIT_CYCLES,
           XSTOP2_WAIT_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pec Invalid dial access XSTOP2_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_WAIT_CYCLES]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
