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

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
