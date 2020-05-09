/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00001.H $            */
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

#ifndef __C_REG00001_H_
#define __C_REG00001_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> PREP_[EC_LS_LSU_HOLD_OUT_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_LS_LSU_HOLD_OUT_REG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_LS_LSU_HOLD_OUT_REG1]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_LS_LSU_HOLD_OUT_REG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG1;
#endif
    return fapi2::getScom(i_target, EC_LS_LSU_HOLD_OUT_REG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1]

//>> PUT_[EC_LS_LSU_HOLD_OUT_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_LS_LSU_HOLD_OUT_REG1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return fapi2::putScom(i_target, EC_LS_LSU_HOLD_OUT_REG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_LS_LSU_HOLD_OUT_REG1]


//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG1_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_0]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_0]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG1_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG1_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_0]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_0]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG1_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG1_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_0]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_0]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG1_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG1_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG1_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_1]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_1]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG1_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG1_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_1]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_1]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG1_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG1_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_1]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_1]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG1_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG1_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG1_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_2]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_2]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG1_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG1_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_2]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_2]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG1_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG1_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_2]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_2]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG1_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG1_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG1_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_3]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_3]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG1_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG1_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_3]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_3]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG1_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG1_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_3]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_3]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG1_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG1_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG1_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_4]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_4]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG1_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG1_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_4]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_4]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG1_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG1_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_4]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_4]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG1_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG1_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG1_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_5]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_5]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG1_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG1_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_5]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_5]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG1_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG1_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_5]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_5]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG1_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG1_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG1_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_6]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_6]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG1_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG1_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_6]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_6]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG1_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG1_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_6]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_6]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG1_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG1_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_7]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_7]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG1_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_7]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_7]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG1_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG1_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_7]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_7]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG1_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG1_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_7]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_7]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG1_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG1_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_7]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_8]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_8]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_8]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_8]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_8]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG1_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_8]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_8]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG1_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG1_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_8]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_8]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG1_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG1_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_8]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_8]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG1_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG1_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_8]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_9]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_9]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_9]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_9]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_9]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG1_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_9]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_9]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG1_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG1_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_9]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_9]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG1_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG1_9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_9]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_9]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG1_9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG1_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_9]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_10]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_10]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_10]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_10]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_10]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG1_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_10]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_10]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG1_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG1_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_10]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_10]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG1_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG1_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_10]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_10]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG1_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG1_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_10]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_11]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_11]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_11]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_11]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_11]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG1_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_11]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_11]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG1_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG1_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_11]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_11]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG1_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG1_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_11]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_11]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG1_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG1_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_11]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_12]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_12]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_12]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_12]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_12]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG1_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_12]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_12]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG1_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG1_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_12]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_12]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG1_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG1_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_12]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_12]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG1_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG1_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_12]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_13]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_13]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_13]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_13]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_13]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG1_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_13]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_13]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG1_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG1_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_13]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_13]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG1_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG1_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_13]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_13]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG1_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG1_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_13]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_14]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_14]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_14]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_14]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_14]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG1_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_14]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_14]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG1_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG1_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_14]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_14]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG1_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG1_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_14]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_14]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG1_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG1_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_14]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_15]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_15]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_15]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG1_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_15]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG1_15]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG1_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG1_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG1_15]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_15]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG1_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG1_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG1_15]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_15]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG1_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG1_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_15]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG1_15]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG1_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG1));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG1_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG1_15]

//>> PREP_[EC_PC_COMMON_SPR_SPATTN_MASK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_COMMON_SPR_SPATTN_MASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_SPATTN_MASK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_COMMON_SPR_SPATTN_MASK]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_MASK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_COMMON_SPR_SPATTN_MASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_SPATTN_MASK;
#endif
    return fapi2::getScom(i_target, EC_PC_COMMON_SPR_SPATTN_MASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_MASK]

//>> PUT_[EC_PC_COMMON_SPR_SPATTN_MASK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_COMMON_SPR_SPATTN_MASK(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return fapi2::putScom(i_target, EC_PC_COMMON_SPR_SPATTN_MASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_COMMON_SPR_SPATTN_MASK]


//>> SET_[EC_PC_COMMON_SPR_SPATTN_MASK_0_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_MASK_0_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_MASK_0_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_0_SPATTN_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_0_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_MASK_0_SPATTN_MASK]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_MASK_0_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_MASK_0_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_MASK_0_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_0_SPATTN_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_0_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_MASK_0_SPATTN_MASK]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_MASK_0_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_MASK_0_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_MASK_0_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_0_SPATTN_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_0_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_MASK_0_SPATTN_MASK]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_MASK_1_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_MASK_1_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_MASK_1_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_1_SPATTN_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_1_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_MASK_1_SPATTN_MASK]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_MASK_1_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_MASK_1_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_MASK_1_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_1_SPATTN_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_1_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_MASK_1_SPATTN_MASK]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_MASK_1_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_MASK_1_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_MASK_1_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_1_SPATTN_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_1_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_MASK_1_SPATTN_MASK]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_MASK_2_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_MASK_2_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_MASK_2_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_2_SPATTN_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_2_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_MASK_2_SPATTN_MASK]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_MASK_2_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_MASK_2_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_MASK_2_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_2_SPATTN_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_2_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_MASK_2_SPATTN_MASK]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_MASK_2_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_MASK_2_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_MASK_2_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_2_SPATTN_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_2_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_MASK_2_SPATTN_MASK]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_MASK_3_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_MASK_3_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_MASK_3_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_3_SPATTN_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_3_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_MASK_3_SPATTN_MASK]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_MASK_3_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_MASK_3_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_MASK_3_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_3_SPATTN_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_3_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_MASK_3_SPATTN_MASK]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_MASK_3_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_MASK_3_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_MASK_3_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_3_SPATTN_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_3_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_MASK_3_SPATTN_MASK]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_MASK_4_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_MASK_4_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_MASK_4_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_4_SPATTN_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_4_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_MASK_4_SPATTN_MASK]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_MASK_4_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_MASK_4_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_MASK_4_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_4_SPATTN_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_4_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_MASK_4_SPATTN_MASK]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_MASK_4_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_MASK_4_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_MASK_4_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_4_SPATTN_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_4_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_MASK_4_SPATTN_MASK]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_MASK_5_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_MASK_5_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_MASK_5_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_5_SPATTN_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_5_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_MASK_5_SPATTN_MASK]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_MASK_5_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_MASK_5_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_MASK_5_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_5_SPATTN_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_5_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_MASK_5_SPATTN_MASK]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_MASK_5_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_MASK_5_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_MASK_5_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_5_SPATTN_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_5_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_MASK_5_SPATTN_MASK]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_MASK_6_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_MASK_6_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_MASK_6_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_6_SPATTN_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_6_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_MASK_6_SPATTN_MASK]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_MASK_6_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_MASK_6_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_MASK_6_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_6_SPATTN_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_6_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_MASK_6_SPATTN_MASK]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_MASK_6_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_MASK_6_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_MASK_6_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_6_SPATTN_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_6_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_MASK_6_SPATTN_MASK]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_MASK_7_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_MASK_7_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_MASK_7_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_7_SPATTN_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_7_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_MASK_7_SPATTN_MASK]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_MASK_7_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_MASK_7_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_MASK_7_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_7_SPATTN_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_7_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_MASK_7_SPATTN_MASK]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_MASK_7_SPATTN_MASK]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_MASK_7_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_MASK));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_MASK_7_SPATTN_MASK,
           EC_PC_COMMON_SPR_SPATTN_MASK_7_SPATTN_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_MASK_7_SPATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_MASK_7_SPATTN_MASK]

//>> PREP_[EC_PC_SCR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_SCR3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SCR3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_SCR3]

//>> GET_[EC_PC_SCR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_SCR3(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SCR3;
#endif
    return fapi2::getScom(i_target, EC_PC_SCR3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_SCR3]

//>> PUT_[EC_PC_SCR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_SCR3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_SCR3));
#endif
    return fapi2::putScom(i_target, EC_PC_SCR3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_SCR3]


//>> PREP_[EC_PC_TRACE1_TR_TR0_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TRACE1_TR_TR0_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE1_TR_TR0_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_TRACE1_TR_TR0_CONFIG]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TRACE1_TR_TR0_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE1_TR_TR0_CONFIG;
#endif
    return fapi2::getScom(i_target, EC_PC_TRACE1_TR_TR0_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG]

//>> PUT_[EC_PC_TRACE1_TR_TR0_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TRACE1_TR_TR0_CONFIG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return fapi2::putScom(i_target, EC_PC_TRACE1_TR_TR0_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_TRACE1_TR_TR0_CONFIG]


//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_STORE_ON_TRIG_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_WRITE_ON_RUN_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_EXTEND_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_EXTEND_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_EXTEND_TRIG_MODE,
           EC_PC_TRACE1_TR_TR0_CONFIG_EXTEND_TRIG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_EXTEND_TRIG_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_EXTEND_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_EXTEND_TRIG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_EXTEND_TRIG_MODE,
           EC_PC_TRACE1_TR_TR0_CONFIG_EXTEND_TRIG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_EXTEND_TRIG_MODE]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_EXTEND_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_EXTEND_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_EXTEND_TRIG_MODE,
           EC_PC_TRACE1_TR_TR0_CONFIG_EXTEND_TRIG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_EXTEND_TRIG_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_BANK_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_ENH_TRACE_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           EC_PC_TRACE1_TR_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           EC_PC_TRACE1_TR_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           EC_PC_TRACE1_TR_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_SELECT_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_SELECT_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_SELECT_CONTROL,
           EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_SELECT_CONTROL]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_SELECT_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_SELECT_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_SELECT_CONTROL,
           EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_SELECT_CONTROL]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_SELECT_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_SELECT_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_SELECT_CONTROL,
           EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_SELECT_CONTROL]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_HOLD_OFF]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STATUS]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_TRACE_RUN_STICKY]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]

//>> PREP_[EC_PC_TRACE2_TR_TR0_CONFIG_1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TRACE2_TR_TR0_CONFIG_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE2_TR_TR0_CONFIG_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_TRACE2_TR_TR0_CONFIG_1]

//>> GET_[EC_PC_TRACE2_TR_TR0_CONFIG_1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TRACE2_TR_TR0_CONFIG_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE2_TR_TR0_CONFIG_1;
#endif
    return fapi2::getScom(i_target, EC_PC_TRACE2_TR_TR0_CONFIG_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_CONFIG_1]

//>> PUT_[EC_PC_TRACE2_TR_TR0_CONFIG_1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TRACE2_TR_TR0_CONFIG_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_1));
#endif
    return fapi2::putScom(i_target, EC_PC_TRACE2_TR_TR0_CONFIG_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_TRACE2_TR_TR0_CONFIG_1]


//>> SET_[EC_PC_TRACE2_TR_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_1));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           EC_PC_TRACE2_TR_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87]

//>> SET_[EC_PC_TRACE2_TR_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_1));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           EC_PC_TRACE2_TR_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87]

//>> GET_[EC_PC_TRACE2_TR_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_1));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           EC_PC_TRACE2_TR_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87]

//>> PREP_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_SD_SDP_SDCR_UNIT_HOLD_OUT0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_SD_SDP_SDCR_UNIT_HOLD_OUT0;
#endif
    return fapi2::getScom(i_target, EC_SD_SDP_SDCR_UNIT_HOLD_OUT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0]

//>> PUT_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return fapi2::putScom(i_target, EC_SD_SDP_SDCR_UNIT_HOLD_OUT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0]


//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_PC_ERR_INJ_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T0_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T1_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T2_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_T3_HEAD_TAIL_XSTOP_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCC_BLOCK_TROUBLE_ERROR]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP0_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP1_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP2_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDCCC_COMP3_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_WAT_INJECT_INT_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_DISP_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_ISSMUX_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_BRDCAST_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDQ_LSU_WKUP_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT0));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT0_SDXM_ERR_HOLD_OUT_0]

//>> PREP_[L2TRA_TR1_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2TRA_TR1_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR1_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2TRA_TR1_CONFIG]

//>> GET_[L2TRA_TR1_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2TRA_TR1_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR1_CONFIG;
#endif
    return fapi2::getScom(i_target, L2TRA_TR1_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG]

//>> PUT_[L2TRA_TR1_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2TRA_TR1_CONFIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return fapi2::putScom(i_target, L2TRA_TR1_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2TRA_TR1_CONFIG]


//>> SET_[L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE]

//>> SET_[L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE]

//>> SET_[L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE]

//>> CLEAR_[L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE]

//>> GET_[L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE]

//>> GET_[L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE]
static inline bool GET_L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE]

//>> SET_[L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE]

//>> SET_[L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE]

//>> SET_[L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE]

//>> CLEAR_[L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE]

//>> GET_[L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE]

//>> GET_[L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE]
static inline bool GET_L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE]

//>> SET_[L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE,
           L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE]

//>> SET_[L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE,
           L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE]

//>> GET_[L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE,
           L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE]

//>> SET_[L2TRA_TR1_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_BANK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_BANK_MODE]

//>> SET_[L2TRA_TR1_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_BANK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_BANK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_BANK_MODE]

//>> SET_[L2TRA_TR1_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_BANK_MODE]

//>> CLEAR_[L2TRA_TR1_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_BANK_MODE]

//>> GET_[L2TRA_TR1_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_BANK_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_BANK_MODE]

//>> GET_[L2TRA_TR1_CONFIG_BANK_MODE]
static inline bool GET_L2TRA_TR1_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_BANK_MODE]

//>> SET_[L2TRA_TR1_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_ENH_TRACE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_ENH_TRACE_MODE]

//>> SET_[L2TRA_TR1_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_ENH_TRACE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_ENH_TRACE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_ENH_TRACE_MODE]

//>> SET_[L2TRA_TR1_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_ENH_TRACE_MODE]

//>> CLEAR_[L2TRA_TR1_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_ENH_TRACE_MODE]

//>> GET_[L2TRA_TR1_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_ENH_TRACE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_ENH_TRACE_MODE]

//>> GET_[L2TRA_TR1_CONFIG_ENH_TRACE_MODE]
static inline bool GET_L2TRA_TR1_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_ENH_TRACE_MODE]

//>> SET_[L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL]

//>> SET_[L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL]

//>> GET_[L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL]

//>> SET_[L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL,
           L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL]

//>> SET_[L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL,
           L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL]

//>> GET_[L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL,
           L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL]

//>> SET_[L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF]

//>> SET_[L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF]

//>> SET_[L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF]

//>> CLEAR_[L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF]

//>> GET_[L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF]

//>> GET_[L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF]
static inline bool GET_L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF]

//>> SET_[L2TRA_TR1_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_TRACE_RUN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_TRACE_RUN_STATUS]

//>> SET_[L2TRA_TR1_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_TRACE_RUN_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_TRACE_RUN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_TRACE_RUN_STATUS]

//>> SET_[L2TRA_TR1_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_TRACE_RUN_STATUS]

//>> CLEAR_[L2TRA_TR1_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_TRACE_RUN_STATUS]

//>> GET_[L2TRA_TR1_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_TRACE_RUN_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_TRACE_RUN_STATUS]

//>> GET_[L2TRA_TR1_CONFIG_TRACE_RUN_STATUS]
static inline bool GET_L2TRA_TR1_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_TRACE_RUN_STATUS]

//>> SET_[L2TRA_TR1_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_TRACE_RUN_STICKY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_TRACE_RUN_STICKY]

//>> SET_[L2TRA_TR1_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_TRACE_RUN_STICKY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_TRACE_RUN_STICKY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_TRACE_RUN_STICKY]

//>> SET_[L2TRA_TR1_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_TRACE_RUN_STICKY]

//>> CLEAR_[L2TRA_TR1_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_TRACE_RUN_STICKY]

//>> GET_[L2TRA_TR1_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_TRACE_RUN_STICKY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_TRACE_RUN_STICKY]

//>> GET_[L2TRA_TR1_CONFIG_TRACE_RUN_STICKY]
static inline bool GET_L2TRA_TR1_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_TRACE_RUN_STICKY]

//>> SET_[L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> SET_[L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> SET_[L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> CLEAR_[L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> GET_[L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> GET_[L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline bool GET_L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> SET_[L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]

//>> SET_[L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]

//>> SET_[L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]

//>> CLEAR_[L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]

//>> GET_[L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]

//>> GET_[L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]
static inline bool GET_L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_DISABLE_SCOM_RD_ACT_OR_ACTIVATE_CROSS]

//>> SET_[L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> SET_[L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> SET_[L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> CLEAR_[L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> GET_[L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> GET_[L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline bool GET_L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> SET_[L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]

//>> SET_[L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]

//>> SET_[L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]

//>> CLEAR_[L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]

//>> GET_[L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]

//>> GET_[L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]
static inline bool GET_L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_CROSS_DISABLE_SCOM_RD_ACT]

//>> PREP_[L2TRA_TR1_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2TRA_TR1_CONFIG_5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR1_CONFIG_5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2TRA_TR1_CONFIG_5]

//>> GET_[L2TRA_TR1_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2TRA_TR1_CONFIG_5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR1_CONFIG_5;
#endif
    return fapi2::getScom(i_target, L2TRA_TR1_CONFIG_5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_5]

//>> PUT_[L2TRA_TR1_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2TRA_TR1_CONFIG_5(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_5));
#endif
    return fapi2::putScom(i_target, L2TRA_TR1_CONFIG_5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2TRA_TR1_CONFIG_5]


//>> SET_[L2TRA_TR1_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_5_C,
           L2TRA_TR1_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_5_C]

//>> SET_[L2TRA_TR1_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_5_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_5_C,
           L2TRA_TR1_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_5_C]

//>> GET_[L2TRA_TR1_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_5));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_5_C,
           L2TRA_TR1_CONFIG_5_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_5_C]

//>> SET_[L2TRA_TR1_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_5_D,
           L2TRA_TR1_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_5_D]

//>> SET_[L2TRA_TR1_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_5_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_5_D,
           L2TRA_TR1_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_5_D]

//>> GET_[L2TRA_TR1_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_5));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_5_D,
           L2TRA_TR1_CONFIG_5_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_5_D]

//>> PREP_[L3_MISC_L3CERRS_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_FIR_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_FIR_REG_RW]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_FIR_REG_RW;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_FIR_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_RW]

//>> PUT_[L3_MISC_L3CERRS_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_FIR_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_FIR_REG_RW]

//>> PREP_[L3_MISC_L3CERRS_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_FIR_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_FIR_REG_WO_AND]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_FIR_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_FIR_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_WO_AND]

//>> PUT_[L3_MISC_L3CERRS_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_FIR_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_FIR_REG_WO_AND]

//>> PREP_[L3_MISC_L3CERRS_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_FIR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_FIR_REG_WO_OR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_FIR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_FIR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_WO_OR]

//>> PUT_[L3_MISC_L3CERRS_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_FIR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_FIR_REG_WO_OR]


//>> SET_[L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_TOPO_TABLE_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_CE_DET_NOT_LINDEL_REQ]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_UE_DET]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_RD_DF_SUE_DET]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_PB]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_PB]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_PB]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_CE_FROM_L2_OR_WIHPC]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_UE_FROM_L2_OR_WIHPC]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_WR_DF_SUE_FROM_L2_OR_WIHPC]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_PB_HANG_POLL]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_NOT_PROX_ERR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_LRU_VIC_SEL_ERROR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_LCO_IN_CHIPLET_ID_MISMATCH]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD]

//>> SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD]

//>> GET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD]
static inline bool GET_L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_REG_RW, L3_MISC_L3CERRS_FIR_REG_WO_AND, L3_MISC_L3CERRS_FIR_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD]

//>> PREP_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD]

//>> PUT_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD]


//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID]

//>> CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID]
static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15]

//>> SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15]

//>> GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15,
           L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15]

//>> PREP_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2]

//>> PUT_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2]


//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23]

//>> PREP_[QME_DCSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_DCSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_DCSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_DCSR]

//>> GET_[QME_DCSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_DCSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_DCSR;
#endif
    return fapi2::getScom(i_target, QME_DCSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_DCSR]

//>> PUT_[QME_DCSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_DCSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return fapi2::putScom(i_target, QME_DCSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_DCSR]


//>> SET_[QME_DCSR_PLS_T0]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_PLS_T0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_PLS_T0,
           QME_DCSR_PLS_T0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_DCSR_PLS_T0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_PLS_T0]

//>> SET_[QME_DCSR_PLS_T0]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_PLS_T0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_PLS_T0,
           QME_DCSR_PLS_T0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_DCSR_PLS_T0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_PLS_T0]

//>> GET_[QME_DCSR_PLS_T0]
static inline fapi2::buffer<uint64_t>& GET_QME_DCSR_PLS_T0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return i_data.extractToRight<QME_DCSR_PLS_T0,
           QME_DCSR_PLS_T0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_DCSR_PLS_T0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DCSR_PLS_T0]

//>> SET_[QME_DCSR_PLS_T1]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_PLS_T1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_PLS_T1,
           QME_DCSR_PLS_T1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_DCSR_PLS_T1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_PLS_T1]

//>> SET_[QME_DCSR_PLS_T1]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_PLS_T1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_PLS_T1,
           QME_DCSR_PLS_T1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_DCSR_PLS_T1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_PLS_T1]

//>> GET_[QME_DCSR_PLS_T1]
static inline fapi2::buffer<uint64_t>& GET_QME_DCSR_PLS_T1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return i_data.extractToRight<QME_DCSR_PLS_T1,
           QME_DCSR_PLS_T1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_DCSR_PLS_T1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DCSR_PLS_T1]

//>> SET_[QME_DCSR_PLS_T2]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_PLS_T2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_PLS_T2,
           QME_DCSR_PLS_T2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_DCSR_PLS_T2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_PLS_T2]

//>> SET_[QME_DCSR_PLS_T2]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_PLS_T2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_PLS_T2,
           QME_DCSR_PLS_T2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_DCSR_PLS_T2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_PLS_T2]

//>> GET_[QME_DCSR_PLS_T2]
static inline fapi2::buffer<uint64_t>& GET_QME_DCSR_PLS_T2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return i_data.extractToRight<QME_DCSR_PLS_T2,
           QME_DCSR_PLS_T2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_DCSR_PLS_T2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DCSR_PLS_T2]

//>> SET_[QME_DCSR_PLS_T3]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_PLS_T3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_PLS_T3,
           QME_DCSR_PLS_T3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_DCSR_PLS_T3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_PLS_T3]

//>> SET_[QME_DCSR_PLS_T3]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_PLS_T3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_PLS_T3,
           QME_DCSR_PLS_T3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_DCSR_PLS_T3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_PLS_T3]

//>> GET_[QME_DCSR_PLS_T3]
static inline fapi2::buffer<uint64_t>& GET_QME_DCSR_PLS_T3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return i_data.extractToRight<QME_DCSR_PLS_T3,
           QME_DCSR_PLS_T3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_DCSR_PLS_T3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DCSR_PLS_T3]

//>> SET_[QME_DCSR_SL_T0]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_SL_T0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_SL_T0,
           QME_DCSR_SL_T0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_DCSR_SL_T0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_SL_T0]

//>> SET_[QME_DCSR_SL_T0]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_SL_T0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_SL_T0,
           QME_DCSR_SL_T0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_DCSR_SL_T0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_SL_T0]

//>> GET_[QME_DCSR_SL_T0]
static inline fapi2::buffer<uint64_t>& GET_QME_DCSR_SL_T0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return i_data.extractToRight<QME_DCSR_SL_T0,
           QME_DCSR_SL_T0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_DCSR_SL_T0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DCSR_SL_T0]

//>> SET_[QME_DCSR_SL_T1]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_SL_T1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_SL_T1,
           QME_DCSR_SL_T1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_DCSR_SL_T1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_SL_T1]

//>> SET_[QME_DCSR_SL_T1]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_SL_T1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_SL_T1,
           QME_DCSR_SL_T1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_DCSR_SL_T1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_SL_T1]

//>> GET_[QME_DCSR_SL_T1]
static inline fapi2::buffer<uint64_t>& GET_QME_DCSR_SL_T1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return i_data.extractToRight<QME_DCSR_SL_T1,
           QME_DCSR_SL_T1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_DCSR_SL_T1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DCSR_SL_T1]

//>> SET_[QME_DCSR_SL_T2]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_SL_T2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_SL_T2,
           QME_DCSR_SL_T2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_DCSR_SL_T2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_SL_T2]

//>> SET_[QME_DCSR_SL_T2]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_SL_T2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_SL_T2,
           QME_DCSR_SL_T2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_DCSR_SL_T2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_SL_T2]

//>> GET_[QME_DCSR_SL_T2]
static inline fapi2::buffer<uint64_t>& GET_QME_DCSR_SL_T2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return i_data.extractToRight<QME_DCSR_SL_T2,
           QME_DCSR_SL_T2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_DCSR_SL_T2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DCSR_SL_T2]

//>> SET_[QME_DCSR_SL_T3]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_SL_T3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_SL_T3,
           QME_DCSR_SL_T3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_DCSR_SL_T3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_SL_T3]

//>> SET_[QME_DCSR_SL_T3]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_SL_T3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_SL_T3,
           QME_DCSR_SL_T3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_DCSR_SL_T3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_SL_T3]

//>> GET_[QME_DCSR_SL_T3]
static inline fapi2::buffer<uint64_t>& GET_QME_DCSR_SL_T3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return i_data.extractToRight<QME_DCSR_SL_T3,
           QME_DCSR_SL_T3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_DCSR_SL_T3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DCSR_SL_T3]

//>> SET_[QME_DCSR_SRESET_MSR_S]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_SRESET_MSR_S(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_SRESET_MSR_S,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_DCSR_SRESET_MSR_S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_SRESET_MSR_S]

//>> SET_[QME_DCSR_SRESET_MSR_S]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_SRESET_MSR_S(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_SRESET_MSR_S,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_DCSR_SRESET_MSR_S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_SRESET_MSR_S]

//>> SET_[QME_DCSR_SRESET_MSR_S]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_SRESET_MSR_S(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.setBit<QME_DCSR_SRESET_MSR_S>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_DCSR_SRESET_MSR_S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_SRESET_MSR_S]

//>> CLEAR_[QME_DCSR_SRESET_MSR_S]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_DCSR_SRESET_MSR_S(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.clearBit<QME_DCSR_SRESET_MSR_S>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_DCSR_SRESET_MSR_S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_DCSR_SRESET_MSR_S]

//>> GET_[QME_DCSR_SRESET_MSR_S]
static inline fapi2::buffer<uint64_t>& GET_QME_DCSR_SRESET_MSR_S(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return i_data.extractToRight<QME_DCSR_SRESET_MSR_S,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_DCSR_SRESET_MSR_S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DCSR_SRESET_MSR_S]

//>> GET_[QME_DCSR_SRESET_MSR_S]
static inline bool GET_QME_DCSR_SRESET_MSR_S(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return i_data.getBit<QME_DCSR_SRESET_MSR_S>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_DCSR_SRESET_MSR_S chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DCSR_SRESET_MSR_S]

//>> SET_[QME_DCSR_THREAD_INSTR_RUNNING_HISTORY]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_THREAD_INSTR_RUNNING_HISTORY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_THREAD_INSTR_RUNNING_HISTORY,
           QME_DCSR_THREAD_INSTR_RUNNING_HISTORY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_DCSR_THREAD_INSTR_RUNNING_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_THREAD_INSTR_RUNNING_HISTORY]

//>> SET_[QME_DCSR_THREAD_INSTR_RUNNING_HISTORY]
static inline fapi2::buffer<uint64_t>& SET_QME_DCSR_THREAD_INSTR_RUNNING_HISTORY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return o_data.insertFromRight<QME_DCSR_THREAD_INSTR_RUNNING_HISTORY,
           QME_DCSR_THREAD_INSTR_RUNNING_HISTORY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_DCSR_THREAD_INSTR_RUNNING_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DCSR_THREAD_INSTR_RUNNING_HISTORY]

//>> GET_[QME_DCSR_THREAD_INSTR_RUNNING_HISTORY]
static inline fapi2::buffer<uint64_t>& GET_QME_DCSR_THREAD_INSTR_RUNNING_HISTORY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DCSR));
#endif
    return i_data.extractToRight<QME_DCSR_THREAD_INSTR_RUNNING_HISTORY,
           QME_DCSR_THREAD_INSTR_RUNNING_HISTORY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_DCSR_THREAD_INSTR_RUNNING_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DCSR_THREAD_INSTR_RUNNING_HISTORY]

//>> PREP_[QME_PMCRS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_PMCRS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PMCRS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_PMCRS]

//>> GET_[QME_PMCRS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_PMCRS(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PMCRS;
#endif
    return fapi2::getScom(i_target, QME_PMCRS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_PMCRS]

//>> PUT_[QME_PMCRS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_PMCRS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_PMCRS));
#endif
    return fapi2::putScom(i_target, QME_PMCRS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_PMCRS]


//>> SET_[QME_PMCRS_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PMCRS_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PMCRS));
#endif
    return o_data.insertFromRight<QME_PMCRS_DATA,
           QME_PMCRS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PMCRS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PMCRS_DATA]

//>> SET_[QME_PMCRS_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PMCRS_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PMCRS));
#endif
    return o_data.insertFromRight<QME_PMCRS_DATA,
           QME_PMCRS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PMCRS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PMCRS_DATA]

//>> GET_[QME_PMCRS_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_PMCRS_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PMCRS));
#endif
    return i_data.extractToRight<QME_PMCRS_DATA,
           QME_PMCRS_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PMCRS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PMCRS_DATA]

//>> PREP_[QME_PMSRS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_PMSRS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PMSRS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_PMSRS]

//>> GET_[QME_PMSRS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_PMSRS(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PMSRS;
#endif
    return fapi2::getScom(i_target, QME_PMSRS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_PMSRS]

//>> PUT_[QME_PMSRS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_PMSRS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_PMSRS));
#endif
    return fapi2::putScom(i_target, QME_PMSRS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_PMSRS]


//>> SET_[QME_PMSRS_PSTATE_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PMSRS_PSTATE_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PMSRS));
#endif
    return o_data.insertFromRight<QME_PMSRS_PSTATE_DATA,
           QME_PMSRS_PSTATE_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PMSRS_PSTATE_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PMSRS_PSTATE_DATA]

//>> SET_[QME_PMSRS_PSTATE_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PMSRS_PSTATE_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PMSRS));
#endif
    return o_data.insertFromRight<QME_PMSRS_PSTATE_DATA,
           QME_PMSRS_PSTATE_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PMSRS_PSTATE_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PMSRS_PSTATE_DATA]

//>> GET_[QME_PMSRS_PSTATE_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_PMSRS_PSTATE_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PMSRS));
#endif
    return i_data.extractToRight<QME_PMSRS_PSTATE_DATA,
           QME_PMSRS_PSTATE_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PMSRS_PSTATE_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PMSRS_PSTATE_DATA]

//>> SET_[QME_PMSRS_INVALID_VERSION]
static inline fapi2::buffer<uint64_t>& SET_QME_PMSRS_INVALID_VERSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PMSRS));
#endif
    return o_data.insertFromRight<QME_PMSRS_INVALID_VERSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PMSRS_INVALID_VERSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PMSRS_INVALID_VERSION]

//>> SET_[QME_PMSRS_INVALID_VERSION]
static inline fapi2::buffer<uint64_t>& SET_QME_PMSRS_INVALID_VERSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PMSRS));
#endif
    return o_data.insertFromRight<QME_PMSRS_INVALID_VERSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PMSRS_INVALID_VERSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PMSRS_INVALID_VERSION]

//>> SET_[QME_PMSRS_INVALID_VERSION]
static inline fapi2::buffer<uint64_t>& SET_QME_PMSRS_INVALID_VERSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PMSRS));
#endif
    return o_data.setBit<QME_PMSRS_INVALID_VERSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PMSRS_INVALID_VERSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PMSRS_INVALID_VERSION]

//>> CLEAR_[QME_PMSRS_INVALID_VERSION]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PMSRS_INVALID_VERSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PMSRS));
#endif
    return o_data.clearBit<QME_PMSRS_INVALID_VERSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PMSRS_INVALID_VERSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PMSRS_INVALID_VERSION]

//>> GET_[QME_PMSRS_INVALID_VERSION]
static inline fapi2::buffer<uint64_t>& GET_QME_PMSRS_INVALID_VERSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PMSRS));
#endif
    return i_data.extractToRight<QME_PMSRS_INVALID_VERSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PMSRS_INVALID_VERSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PMSRS_INVALID_VERSION]

//>> GET_[QME_PMSRS_INVALID_VERSION]
static inline bool GET_QME_PMSRS_INVALID_VERSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PMSRS));
#endif
    return i_data.getBit<QME_PMSRS_INVALID_VERSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PMSRS_INVALID_VERSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PMSRS_INVALID_VERSION]

//>> SET_[QME_PMSRS_VERSION]
static inline fapi2::buffer<uint64_t>& SET_QME_PMSRS_VERSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PMSRS));
#endif
    return o_data.insertFromRight<QME_PMSRS_VERSION,
           QME_PMSRS_VERSION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PMSRS_VERSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PMSRS_VERSION]

//>> SET_[QME_PMSRS_VERSION]
static inline fapi2::buffer<uint64_t>& SET_QME_PMSRS_VERSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PMSRS));
#endif
    return o_data.insertFromRight<QME_PMSRS_VERSION,
           QME_PMSRS_VERSION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PMSRS_VERSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PMSRS_VERSION]

//>> GET_[QME_PMSRS_VERSION]
static inline fapi2::buffer<uint64_t>& GET_QME_PMSRS_VERSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PMSRS));
#endif
    return i_data.extractToRight<QME_PMSRS_VERSION,
           QME_PMSRS_VERSION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PMSRS_VERSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PMSRS_VERSION]

//>> PREP_[QME_PSCRS2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_PSCRS2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PSCRS2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_PSCRS2]

//>> GET_[QME_PSCRS2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_PSCRS2(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PSCRS2;
#endif
    return fapi2::getScom(i_target, QME_PSCRS2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_PSCRS2]

//>> PUT_[QME_PSCRS2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_PSCRS2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return fapi2::putScom(i_target, QME_PSCRS2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_PSCRS2]


//>> SET_[QME_PSCRS2_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_DPDES_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS2_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_DPDES_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_DPDES_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_DPDES_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS2_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_DPDES_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.setBit<QME_PSCRS2_DPDES_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS2_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_DPDES_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS2_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS2_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.clearBit<QME_PSCRS2_DPDES_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS2_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS2_DPDES_EXIT_ENABLE]

//>> GET_[QME_PSCRS2_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS2_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.extractToRight<QME_PSCRS2_DPDES_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS2_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_DPDES_EXIT_ENABLE]

//>> GET_[QME_PSCRS2_DPDES_EXIT_ENABLE]
static inline bool GET_QME_PSCRS2_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.getBit<QME_PSCRS2_DPDES_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS2_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_DPDES_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_SD]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_SD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_SD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS2_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_SD]

//>> SET_[QME_PSCRS2_SD]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_SD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_SD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS2_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_SD]

//>> SET_[QME_PSCRS2_SD]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_SD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.setBit<QME_PSCRS2_SD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS2_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_SD]

//>> CLEAR_[QME_PSCRS2_SD]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS2_SD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.clearBit<QME_PSCRS2_SD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS2_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS2_SD]

//>> GET_[QME_PSCRS2_SD]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS2_SD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.extractToRight<QME_PSCRS2_SD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS2_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_SD]

//>> GET_[QME_PSCRS2_SD]
static inline bool GET_QME_PSCRS2_SD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.getBit<QME_PSCRS2_SD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS2_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_SD]

//>> SET_[QME_PSCRS2_ESL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_ESL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_ESL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS2_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_ESL]

//>> SET_[QME_PSCRS2_ESL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_ESL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_ESL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS2_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_ESL]

//>> SET_[QME_PSCRS2_ESL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_ESL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.setBit<QME_PSCRS2_ESL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS2_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_ESL]

//>> CLEAR_[QME_PSCRS2_ESL]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS2_ESL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.clearBit<QME_PSCRS2_ESL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS2_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS2_ESL]

//>> GET_[QME_PSCRS2_ESL]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS2_ESL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.extractToRight<QME_PSCRS2_ESL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS2_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_ESL]

//>> GET_[QME_PSCRS2_ESL]
static inline bool GET_QME_PSCRS2_ESL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.getBit<QME_PSCRS2_ESL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS2_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_ESL]

//>> SET_[QME_PSCRS2_EC]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_EC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_EC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS2_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_EC]

//>> SET_[QME_PSCRS2_EC]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_EC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_EC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS2_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_EC]

//>> SET_[QME_PSCRS2_EC]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_EC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.setBit<QME_PSCRS2_EC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS2_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_EC]

//>> CLEAR_[QME_PSCRS2_EC]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS2_EC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.clearBit<QME_PSCRS2_EC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS2_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS2_EC]

//>> GET_[QME_PSCRS2_EC]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS2_EC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.extractToRight<QME_PSCRS2_EC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS2_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_EC]

//>> GET_[QME_PSCRS2_EC]
static inline bool GET_QME_PSCRS2_EC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.getBit<QME_PSCRS2_EC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS2_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_EC]

//>> SET_[QME_PSCRS2_PSLL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_PSLL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_PSLL,
           QME_PSCRS2_PSLL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS2_PSLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_PSLL]

//>> SET_[QME_PSCRS2_PSLL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_PSLL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_PSLL,
           QME_PSCRS2_PSLL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS2_PSLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_PSLL]

//>> GET_[QME_PSCRS2_PSLL]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS2_PSLL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.extractToRight<QME_PSCRS2_PSLL,
           QME_PSCRS2_PSLL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS2_PSLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_PSLL]

//>> SET_[QME_PSCRS2_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_HYP_VIRT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS2_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_HYP_VIRT_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_HYP_VIRT_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_HYP_VIRT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS2_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_HYP_VIRT_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.setBit<QME_PSCRS2_HYP_VIRT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS2_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_HYP_VIRT_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS2_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS2_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.clearBit<QME_PSCRS2_HYP_VIRT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS2_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS2_HYP_VIRT_EXIT_ENABLE]

//>> GET_[QME_PSCRS2_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS2_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.extractToRight<QME_PSCRS2_HYP_VIRT_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS2_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_HYP_VIRT_EXIT_ENABLE]

//>> GET_[QME_PSCRS2_HYP_VIRT_EXIT_ENABLE]
static inline bool GET_QME_PSCRS2_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.getBit<QME_PSCRS2_HYP_VIRT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS2_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_HYP_VIRT_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_UV_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS2_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_UV_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_UV_DB_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_UV_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS2_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_UV_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.setBit<QME_PSCRS2_UV_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS2_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_UV_DB_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS2_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS2_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.clearBit<QME_PSCRS2_UV_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS2_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS2_UV_DB_EXIT_ENABLE]

//>> GET_[QME_PSCRS2_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS2_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.extractToRight<QME_PSCRS2_UV_DB_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS2_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_UV_DB_EXIT_ENABLE]

//>> GET_[QME_PSCRS2_UV_DB_EXIT_ENABLE]
static inline bool GET_QME_PSCRS2_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.getBit<QME_PSCRS2_UV_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS2_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_UV_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_HYP_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS2_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_HYP_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_HYP_DB_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_HYP_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS2_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_HYP_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.setBit<QME_PSCRS2_HYP_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS2_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_HYP_DB_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS2_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS2_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.clearBit<QME_PSCRS2_HYP_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS2_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS2_HYP_DB_EXIT_ENABLE]

//>> GET_[QME_PSCRS2_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS2_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.extractToRight<QME_PSCRS2_HYP_DB_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS2_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_HYP_DB_EXIT_ENABLE]

//>> GET_[QME_PSCRS2_HYP_DB_EXIT_ENABLE]
static inline bool GET_QME_PSCRS2_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.getBit<QME_PSCRS2_HYP_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS2_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_HYP_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_EXT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS2_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_EXT_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_EXT_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_EXT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS2_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_EXT_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.setBit<QME_PSCRS2_EXT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS2_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_EXT_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS2_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS2_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.clearBit<QME_PSCRS2_EXT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS2_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS2_EXT_EXIT_ENABLE]

//>> GET_[QME_PSCRS2_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS2_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.extractToRight<QME_PSCRS2_EXT_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS2_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_EXT_EXIT_ENABLE]

//>> GET_[QME_PSCRS2_EXT_EXIT_ENABLE]
static inline bool GET_QME_PSCRS2_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.getBit<QME_PSCRS2_EXT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS2_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_EXT_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_DEC_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS2_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_DEC_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_DEC_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_DEC_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS2_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_DEC_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.setBit<QME_PSCRS2_DEC_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS2_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_DEC_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS2_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS2_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.clearBit<QME_PSCRS2_DEC_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS2_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS2_DEC_EXIT_ENABLE]

//>> GET_[QME_PSCRS2_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS2_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.extractToRight<QME_PSCRS2_DEC_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS2_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_DEC_EXIT_ENABLE]

//>> GET_[QME_PSCRS2_DEC_EXIT_ENABLE]
static inline bool GET_QME_PSCRS2_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.getBit<QME_PSCRS2_DEC_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS2_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_DEC_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_HMI_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS2_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_HMI_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_HMI_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_HMI_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS2_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_HMI_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.setBit<QME_PSCRS2_HMI_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS2_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_HMI_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS2_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS2_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.clearBit<QME_PSCRS2_HMI_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS2_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS2_HMI_EXIT_ENABLE]

//>> GET_[QME_PSCRS2_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS2_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.extractToRight<QME_PSCRS2_HMI_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS2_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_HMI_EXIT_ENABLE]

//>> GET_[QME_PSCRS2_HMI_EXIT_ENABLE]
static inline bool GET_QME_PSCRS2_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.getBit<QME_PSCRS2_HMI_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS2_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_HMI_EXIT_ENABLE]

//>> SET_[QME_PSCRS2_TR]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_TR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_TR,
           QME_PSCRS2_TR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS2_TR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_TR]

//>> SET_[QME_PSCRS2_TR]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_TR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_TR,
           QME_PSCRS2_TR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS2_TR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_TR]

//>> GET_[QME_PSCRS2_TR]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS2_TR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.extractToRight<QME_PSCRS2_TR,
           QME_PSCRS2_TR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS2_TR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_TR]

//>> SET_[QME_PSCRS2_MTL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_MTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_MTL,
           QME_PSCRS2_MTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS2_MTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_MTL]

//>> SET_[QME_PSCRS2_MTL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_MTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_MTL,
           QME_PSCRS2_MTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS2_MTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_MTL]

//>> GET_[QME_PSCRS2_MTL]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS2_MTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.extractToRight<QME_PSCRS2_MTL,
           QME_PSCRS2_MTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS2_MTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_MTL]

//>> SET_[QME_PSCRS2_RL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_RL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_RL,
           QME_PSCRS2_RL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS2_RL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_RL]

//>> SET_[QME_PSCRS2_RL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_RL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_RL,
           QME_PSCRS2_RL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS2_RL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_RL]

//>> GET_[QME_PSCRS2_RL]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS2_RL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.extractToRight<QME_PSCRS2_RL,
           QME_PSCRS2_RL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS2_RL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_RL]

//>> SET_[QME_PSCRS2_PLS]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_PLS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_PLS,
           QME_PSCRS2_PLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS2_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_PLS]

//>> SET_[QME_PSCRS2_PLS]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS2_PLS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return o_data.insertFromRight<QME_PSCRS2_PLS,
           QME_PSCRS2_PLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS2_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS2_PLS]

//>> GET_[QME_PSCRS2_PLS]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS2_PLS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS2));
#endif
    return i_data.extractToRight<QME_PSCRS2_PLS,
           QME_PSCRS2_PLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS2_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS2_PLS]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
