/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00005.H $            */
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

#ifndef __C_REG00005_H_
#define __C_REG00005_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> PREP_[ADDR_TRAP_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ADDR_TRAP_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ADDR_TRAP_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[ADDR_TRAP_REG]

//>> GET_[ADDR_TRAP_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ADDR_TRAP_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ADDR_TRAP_REG;
#endif
    return fapi2::getScom(i_target, ADDR_TRAP_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[ADDR_TRAP_REG]

//>> PUT_[ADDR_TRAP_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ADDR_TRAP_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return fapi2::putScom(i_target, ADDR_TRAP_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[ADDR_TRAP_REG]


//>> SET_[ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR,
           ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR]

//>> SET_[ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR,
           ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR]

//>> GET_[ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR,
           ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR]

//>> SET_[ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]

//>> SET_[ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]

//>> SET_[ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.setBit<ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]

//>> CLEAR_[ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.clearBit<ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]

//>> GET_[ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]

//>> GET_[ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]
static inline bool GET_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return i_data.getBit<ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR]

//>> SET_[ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]

//>> SET_[ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]

//>> SET_[ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.setBit<ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]

//>> CLEAR_[ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.clearBit<ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]

//>> GET_[ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]
static inline fapi2::buffer<uint64_t>& GET_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]

//>> GET_[ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]
static inline bool GET_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return i_data.getBit<ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT]

//>> SET_[ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR,
           ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR]

//>> SET_[ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR,
           ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR]

//>> GET_[ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR,
           ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR]

//>> SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]

//>> SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]

//>> SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.setBit<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]

//>> CLEAR_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]
static inline fapi2::buffer<uint64_t>& CLEAR_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.clearBit<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]

//>> GET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]
static inline fapi2::buffer<uint64_t>& GET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]

//>> GET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]
static inline bool GET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return i_data.getBit<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY]

//>> SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]

//>> SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]

//>> SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.setBit<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]

//>> CLEAR_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.clearBit<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]

//>> GET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]

//>> GET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]
static inline bool GET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return i_data.getBit<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR]

//>> SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]

//>> SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]

//>> SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.setBit<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]

//>> CLEAR_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& CLEAR_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.clearBit<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]

//>> GET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& GET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]

//>> GET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]
static inline bool GET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return i_data.getBit<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION]

//>> SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]

//>> SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]

//>> SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.setBit<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]

//>> CLEAR_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]
static inline fapi2::buffer<uint64_t>& CLEAR_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.clearBit<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]

//>> GET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]
static inline fapi2::buffer<uint64_t>& GET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]

//>> GET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]
static inline bool GET_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return i_data.getBit<ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER]

//>> SET_[ADDR_TRAP_REG_LAST_MASTERID]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_LAST_MASTERID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<ADDR_TRAP_REG_LAST_MASTERID,
           ADDR_TRAP_REG_LAST_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access ADDR_TRAP_REG_LAST_MASTERID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_LAST_MASTERID]

//>> SET_[ADDR_TRAP_REG_LAST_MASTERID]
static inline fapi2::buffer<uint64_t>& SET_ADDR_TRAP_REG_LAST_MASTERID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return o_data.insertFromRight<ADDR_TRAP_REG_LAST_MASTERID,
           ADDR_TRAP_REG_LAST_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access ADDR_TRAP_REG_LAST_MASTERID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ADDR_TRAP_REG_LAST_MASTERID]

//>> GET_[ADDR_TRAP_REG_LAST_MASTERID]
static inline fapi2::buffer<uint64_t>& GET_ADDR_TRAP_REG_LAST_MASTERID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ADDR_TRAP_REG));
#endif
    return i_data.extractToRight<ADDR_TRAP_REG_LAST_MASTERID,
           ADDR_TRAP_REG_LAST_MASTERID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access ADDR_TRAP_REG_LAST_MASTERID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ADDR_TRAP_REG_LAST_MASTERID]

//>> PREP_[CPMS_FLMR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_FLMR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FLMR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_FLMR_RW]

//>> GET_[CPMS_FLMR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_FLMR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FLMR_RW;
#endif
    return fapi2::getScom(i_target, CPMS_FLMR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_FLMR_RW]

//>> PUT_[CPMS_FLMR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_FLMR_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_FLMR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_FLMR_RW]

//>> PREP_[CPMS_FLMR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_FLMR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FLMR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_FLMR_WO_CLEAR]

//>> GET_[CPMS_FLMR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_FLMR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FLMR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPMS_FLMR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_FLMR_WO_CLEAR]

//>> PUT_[CPMS_FLMR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_FLMR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_FLMR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_FLMR_WO_CLEAR]

//>> PREP_[CPMS_FLMR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_FLMR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FLMR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_FLMR_WO_OR]

//>> GET_[CPMS_FLMR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_FLMR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FLMR_WO_OR;
#endif
    return fapi2::getScom(i_target, CPMS_FLMR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_FLMR_WO_OR]

//>> PUT_[CPMS_FLMR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_FLMR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_FLMR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_FLMR_WO_OR]


//>> SET_[CPMS_FLMR_LARGE_INITIAL_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_INITIAL_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_INITIAL_CYCLES,
           CPMS_FLMR_LARGE_INITIAL_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_LARGE_INITIAL_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_INITIAL_CYCLES]

//>> SET_[CPMS_FLMR_LARGE_INITIAL_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_INITIAL_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_INITIAL_CYCLES,
           CPMS_FLMR_LARGE_INITIAL_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_LARGE_INITIAL_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_INITIAL_CYCLES]

//>> GET_[CPMS_FLMR_LARGE_INITIAL_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_LARGE_INITIAL_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_LARGE_INITIAL_CYCLES,
           CPMS_FLMR_LARGE_INITIAL_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_LARGE_INITIAL_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_INITIAL_CYCLES]

//>> SET_[CPMS_FLMR_LARGE_INITIAL_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_INITIAL_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_INITIAL_ACTION,
           CPMS_FLMR_LARGE_INITIAL_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_LARGE_INITIAL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_INITIAL_ACTION]

//>> SET_[CPMS_FLMR_LARGE_INITIAL_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_INITIAL_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_INITIAL_ACTION,
           CPMS_FLMR_LARGE_INITIAL_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_LARGE_INITIAL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_INITIAL_ACTION]

//>> GET_[CPMS_FLMR_LARGE_INITIAL_ACTION]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_LARGE_INITIAL_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_LARGE_INITIAL_ACTION,
           CPMS_FLMR_LARGE_INITIAL_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_LARGE_INITIAL_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_INITIAL_ACTION]

//>> SET_[CPMS_FLMR_LARGE_PREFETCH_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_PREFETCH_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_PREFETCH_ACTION,
           CPMS_FLMR_LARGE_PREFETCH_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_LARGE_PREFETCH_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_PREFETCH_ACTION]

//>> SET_[CPMS_FLMR_LARGE_PREFETCH_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_PREFETCH_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_PREFETCH_ACTION,
           CPMS_FLMR_LARGE_PREFETCH_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_LARGE_PREFETCH_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_PREFETCH_ACTION]

//>> GET_[CPMS_FLMR_LARGE_PREFETCH_ACTION]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_LARGE_PREFETCH_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_LARGE_PREFETCH_ACTION,
           CPMS_FLMR_LARGE_PREFETCH_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_LARGE_PREFETCH_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_PREFETCH_ACTION]

//>> SET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_RESPONSE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_RESPONSE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_LARGE_RESPONSE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]

//>> SET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_RESPONSE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_RESPONSE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_LARGE_RESPONSE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]

//>> SET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_RESPONSE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_LARGE_RESPONSE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_LARGE_RESPONSE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]

//>> CLEAR_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_LARGE_RESPONSE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_LARGE_RESPONSE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_LARGE_RESPONSE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]

//>> GET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_LARGE_RESPONSE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_LARGE_RESPONSE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_LARGE_RESPONSE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]

//>> GET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]
static inline bool GET_CPMS_FLMR_LARGE_RESPONSE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_LARGE_RESPONSE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_LARGE_RESPONSE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_RESPONSE_DISABLE]

//>> SET_[CPMS_FLMR_LARGE_FLUSH_TYPE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_FLUSH_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_FLUSH_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_LARGE_FLUSH_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_FLUSH_TYPE]

//>> SET_[CPMS_FLMR_LARGE_FLUSH_TYPE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_FLUSH_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_FLUSH_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_LARGE_FLUSH_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_FLUSH_TYPE]

//>> SET_[CPMS_FLMR_LARGE_FLUSH_TYPE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_FLUSH_TYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_LARGE_FLUSH_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_LARGE_FLUSH_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_FLUSH_TYPE]

//>> CLEAR_[CPMS_FLMR_LARGE_FLUSH_TYPE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_LARGE_FLUSH_TYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_LARGE_FLUSH_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_LARGE_FLUSH_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_LARGE_FLUSH_TYPE]

//>> GET_[CPMS_FLMR_LARGE_FLUSH_TYPE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_LARGE_FLUSH_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_LARGE_FLUSH_TYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_LARGE_FLUSH_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_FLUSH_TYPE]

//>> GET_[CPMS_FLMR_LARGE_FLUSH_TYPE]
static inline bool GET_CPMS_FLMR_LARGE_FLUSH_TYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_LARGE_FLUSH_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_LARGE_FLUSH_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_FLUSH_TYPE]

//>> SET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_DITHER_WINDOW_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_DITHER_WINDOW_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]

//>> SET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_DITHER_WINDOW_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_DITHER_WINDOW_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]

//>> SET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_DITHER_WINDOW_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_LARGE_DITHER_WINDOW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]

//>> CLEAR_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_LARGE_DITHER_WINDOW_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_LARGE_DITHER_WINDOW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]

//>> GET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_LARGE_DITHER_WINDOW_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_LARGE_DITHER_WINDOW_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]

//>> GET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]
static inline bool GET_CPMS_FLMR_LARGE_DITHER_WINDOW_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_LARGE_DITHER_WINDOW_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_WINDOW_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_DITHER_WINDOW_SEL]

//>> SET_[CPMS_FLMR_LARGE_DITHER_INITIAL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_DITHER_INITIAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_DITHER_INITIAL,
           CPMS_FLMR_LARGE_DITHER_INITIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_INITIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_DITHER_INITIAL]

//>> SET_[CPMS_FLMR_LARGE_DITHER_INITIAL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_DITHER_INITIAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_DITHER_INITIAL,
           CPMS_FLMR_LARGE_DITHER_INITIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_INITIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_DITHER_INITIAL]

//>> GET_[CPMS_FLMR_LARGE_DITHER_INITIAL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_LARGE_DITHER_INITIAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_LARGE_DITHER_INITIAL,
           CPMS_FLMR_LARGE_DITHER_INITIAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_INITIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_DITHER_INITIAL]

//>> SET_[CPMS_FLMR_LARGE_DITHER_REPEAT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_DITHER_REPEAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_DITHER_REPEAT,
           CPMS_FLMR_LARGE_DITHER_REPEAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_REPEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_DITHER_REPEAT]

//>> SET_[CPMS_FLMR_LARGE_DITHER_REPEAT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_DITHER_REPEAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_DITHER_REPEAT,
           CPMS_FLMR_LARGE_DITHER_REPEAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_REPEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_DITHER_REPEAT]

//>> GET_[CPMS_FLMR_LARGE_DITHER_REPEAT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_LARGE_DITHER_REPEAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_LARGE_DITHER_REPEAT,
           CPMS_FLMR_LARGE_DITHER_REPEAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_REPEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_DITHER_REPEAT]

//>> SET_[CPMS_FLMR_LARGE_DITHER_INCREASE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_DITHER_INCREASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_DITHER_INCREASE,
           CPMS_FLMR_LARGE_DITHER_INCREASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_INCREASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_DITHER_INCREASE]

//>> SET_[CPMS_FLMR_LARGE_DITHER_INCREASE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_LARGE_DITHER_INCREASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_LARGE_DITHER_INCREASE,
           CPMS_FLMR_LARGE_DITHER_INCREASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_INCREASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_LARGE_DITHER_INCREASE]

//>> GET_[CPMS_FLMR_LARGE_DITHER_INCREASE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_LARGE_DITHER_INCREASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_LARGE_DITHER_INCREASE,
           CPMS_FLMR_LARGE_DITHER_INCREASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_LARGE_DITHER_INCREASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_LARGE_DITHER_INCREASE]

//>> SET_[CPMS_FLMR_PHASE1_RECOVERY_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE1_RECOVERY_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE1_RECOVERY_ACTION,
           CPMS_FLMR_PHASE1_RECOVERY_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_PHASE1_RECOVERY_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE1_RECOVERY_ACTION]

//>> SET_[CPMS_FLMR_PHASE1_RECOVERY_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE1_RECOVERY_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE1_RECOVERY_ACTION,
           CPMS_FLMR_PHASE1_RECOVERY_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_PHASE1_RECOVERY_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE1_RECOVERY_ACTION]

//>> GET_[CPMS_FLMR_PHASE1_RECOVERY_ACTION]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_PHASE1_RECOVERY_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_PHASE1_RECOVERY_ACTION,
           CPMS_FLMR_PHASE1_RECOVERY_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_PHASE1_RECOVERY_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_PHASE1_RECOVERY_ACTION]

//>> SET_[CPMS_FLMR_PHASE1_RECOVERY_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE1_RECOVERY_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE1_RECOVERY_PREFETCH,
           CPMS_FLMR_PHASE1_RECOVERY_PREFETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_PHASE1_RECOVERY_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE1_RECOVERY_PREFETCH]

//>> SET_[CPMS_FLMR_PHASE1_RECOVERY_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE1_RECOVERY_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE1_RECOVERY_PREFETCH,
           CPMS_FLMR_PHASE1_RECOVERY_PREFETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_PHASE1_RECOVERY_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE1_RECOVERY_PREFETCH]

//>> GET_[CPMS_FLMR_PHASE1_RECOVERY_PREFETCH]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_PHASE1_RECOVERY_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_PHASE1_RECOVERY_PREFETCH,
           CPMS_FLMR_PHASE1_RECOVERY_PREFETCH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_PHASE1_RECOVERY_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_PHASE1_RECOVERY_PREFETCH]

//>> SET_[CPMS_FLMR_PHASE1_RECOVERY_VECTOR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE1_RECOVERY_VECTOR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE1_RECOVERY_VECTOR,
           CPMS_FLMR_PHASE1_RECOVERY_VECTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_PHASE1_RECOVERY_VECTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE1_RECOVERY_VECTOR]

//>> SET_[CPMS_FLMR_PHASE1_RECOVERY_VECTOR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE1_RECOVERY_VECTOR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE1_RECOVERY_VECTOR,
           CPMS_FLMR_PHASE1_RECOVERY_VECTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_PHASE1_RECOVERY_VECTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE1_RECOVERY_VECTOR]

//>> GET_[CPMS_FLMR_PHASE1_RECOVERY_VECTOR]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_PHASE1_RECOVERY_VECTOR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_PHASE1_RECOVERY_VECTOR,
           CPMS_FLMR_PHASE1_RECOVERY_VECTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_PHASE1_RECOVERY_VECTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_PHASE1_RECOVERY_VECTOR]

//>> SET_[CPMS_FLMR_PHASE2_RECOVERY_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE2_RECOVERY_ACTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE2_RECOVERY_ACTION,
           CPMS_FLMR_PHASE2_RECOVERY_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE2_RECOVERY_ACTION]

//>> SET_[CPMS_FLMR_PHASE2_RECOVERY_ACTION]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE2_RECOVERY_ACTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE2_RECOVERY_ACTION,
           CPMS_FLMR_PHASE2_RECOVERY_ACTION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE2_RECOVERY_ACTION]

//>> GET_[CPMS_FLMR_PHASE2_RECOVERY_ACTION]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_PHASE2_RECOVERY_ACTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_PHASE2_RECOVERY_ACTION,
           CPMS_FLMR_PHASE2_RECOVERY_ACTION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_ACTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_PHASE2_RECOVERY_ACTION]

//>> SET_[CPMS_FLMR_PHASE2_RECOVERY_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE2_RECOVERY_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE2_RECOVERY_PREFETCH,
           CPMS_FLMR_PHASE2_RECOVERY_PREFETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE2_RECOVERY_PREFETCH]

//>> SET_[CPMS_FLMR_PHASE2_RECOVERY_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE2_RECOVERY_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE2_RECOVERY_PREFETCH,
           CPMS_FLMR_PHASE2_RECOVERY_PREFETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE2_RECOVERY_PREFETCH]

//>> GET_[CPMS_FLMR_PHASE2_RECOVERY_PREFETCH]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_PHASE2_RECOVERY_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_PHASE2_RECOVERY_PREFETCH,
           CPMS_FLMR_PHASE2_RECOVERY_PREFETCH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_PHASE2_RECOVERY_PREFETCH]

//>> SET_[CPMS_FLMR_PHASE2_RECOVERY_VECTOR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE2_RECOVERY_VECTOR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE2_RECOVERY_VECTOR,
           CPMS_FLMR_PHASE2_RECOVERY_VECTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_VECTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE2_RECOVERY_VECTOR]

//>> SET_[CPMS_FLMR_PHASE2_RECOVERY_VECTOR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE2_RECOVERY_VECTOR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE2_RECOVERY_VECTOR,
           CPMS_FLMR_PHASE2_RECOVERY_VECTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_VECTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE2_RECOVERY_VECTOR]

//>> GET_[CPMS_FLMR_PHASE2_RECOVERY_VECTOR]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_PHASE2_RECOVERY_VECTOR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_PHASE2_RECOVERY_VECTOR,
           CPMS_FLMR_PHASE2_RECOVERY_VECTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_VECTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_PHASE2_RECOVERY_VECTOR]

//>> SET_[CPMS_FLMR_PHASE2_RECOVERY_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE2_RECOVERY_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE2_RECOVERY_CYCLES,
           CPMS_FLMR_PHASE2_RECOVERY_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE2_RECOVERY_CYCLES]

//>> SET_[CPMS_FLMR_PHASE2_RECOVERY_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE2_RECOVERY_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE2_RECOVERY_CYCLES,
           CPMS_FLMR_PHASE2_RECOVERY_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE2_RECOVERY_CYCLES]

//>> GET_[CPMS_FLMR_PHASE2_RECOVERY_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_PHASE2_RECOVERY_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_PHASE2_RECOVERY_CYCLES,
           CPMS_FLMR_PHASE2_RECOVERY_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_PHASE2_RECOVERY_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_PHASE2_RECOVERY_CYCLES]

//>> SET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]

//>> SET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]

//>> SET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]

//>> CLEAR_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]

//>> GET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]

//>> GET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]
static inline bool GET_CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE]

//>> SET_[CPMS_FLMR_MMA_DROOP_PREDICT_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_MMA_DROOP_PREDICT_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_MMA_DROOP_PREDICT_SELECT,
           CPMS_FLMR_MMA_DROOP_PREDICT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_MMA_DROOP_PREDICT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_MMA_DROOP_PREDICT_SELECT]

//>> SET_[CPMS_FLMR_MMA_DROOP_PREDICT_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_MMA_DROOP_PREDICT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_MMA_DROOP_PREDICT_SELECT,
           CPMS_FLMR_MMA_DROOP_PREDICT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_MMA_DROOP_PREDICT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_MMA_DROOP_PREDICT_SELECT]

//>> GET_[CPMS_FLMR_MMA_DROOP_PREDICT_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_MMA_DROOP_PREDICT_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_MMA_DROOP_PREDICT_SELECT,
           CPMS_FLMR_MMA_DROOP_PREDICT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_MMA_DROOP_PREDICT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_MMA_DROOP_PREDICT_SELECT]

//>> SET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_IDLE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_CORE_UCODE_IDLE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_IDLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]

//>> SET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_IDLE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_CORE_UCODE_IDLE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_IDLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]

//>> SET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_IDLE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_CORE_UCODE_IDLE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_IDLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]

//>> CLEAR_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_CORE_UCODE_IDLE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_CORE_UCODE_IDLE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_IDLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]

//>> GET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_CORE_UCODE_IDLE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_CORE_UCODE_IDLE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_IDLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]

//>> GET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]
static inline bool GET_CPMS_FLMR_CORE_UCODE_IDLE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_CORE_UCODE_IDLE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_IDLE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_CORE_UCODE_IDLE_DISABLE]

//>> SET_[CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS,
           CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS]

//>> SET_[CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS,
           CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS]

//>> GET_[CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS,
           CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS]

//>> SET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_GRANT_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_CORE_UCODE_GRANT_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_GRANT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]

//>> SET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_GRANT_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_CORE_UCODE_GRANT_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_GRANT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]

//>> SET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_GRANT_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_CORE_UCODE_GRANT_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_GRANT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]

//>> CLEAR_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_CORE_UCODE_GRANT_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_CORE_UCODE_GRANT_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_GRANT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]

//>> GET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_CORE_UCODE_GRANT_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_CORE_UCODE_GRANT_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_GRANT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]

//>> GET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]
static inline bool GET_CPMS_FLMR_CORE_UCODE_GRANT_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_CORE_UCODE_GRANT_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_GRANT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_CORE_UCODE_GRANT_INJECT]

//>> SET_[CPMS_FLMR_FTC_RESET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_FTC_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_FTC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_FTC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_FTC_RESET]

//>> SET_[CPMS_FLMR_FTC_RESET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_FTC_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_FTC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_FTC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_FTC_RESET]

//>> SET_[CPMS_FLMR_FTC_RESET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_FTC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_FTC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_FTC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_FTC_RESET]

//>> CLEAR_[CPMS_FLMR_FTC_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_FTC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_FTC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_FTC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_FTC_RESET]

//>> GET_[CPMS_FLMR_FTC_RESET]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_FTC_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_FTC_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_FTC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_FTC_RESET]

//>> GET_[CPMS_FLMR_FTC_RESET]
static inline bool GET_CPMS_FLMR_FTC_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_FTC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_FTC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_FTC_RESET]

//>> SET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]

//>> SET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]

//>> SET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]

//>> CLEAR_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]

//>> GET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]

//>> GET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]
static inline bool GET_CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE]

//>> SET_[CPMS_FLMR_PHASE1_DITHER_NTC]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE1_DITHER_NTC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE1_DITHER_NTC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_PHASE1_DITHER_NTC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE1_DITHER_NTC]

//>> SET_[CPMS_FLMR_PHASE1_DITHER_NTC]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE1_DITHER_NTC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_PHASE1_DITHER_NTC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_PHASE1_DITHER_NTC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE1_DITHER_NTC]

//>> SET_[CPMS_FLMR_PHASE1_DITHER_NTC]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_PHASE1_DITHER_NTC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_PHASE1_DITHER_NTC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_PHASE1_DITHER_NTC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_PHASE1_DITHER_NTC]

//>> CLEAR_[CPMS_FLMR_PHASE1_DITHER_NTC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_PHASE1_DITHER_NTC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_PHASE1_DITHER_NTC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_PHASE1_DITHER_NTC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_PHASE1_DITHER_NTC]

//>> GET_[CPMS_FLMR_PHASE1_DITHER_NTC]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_PHASE1_DITHER_NTC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_PHASE1_DITHER_NTC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_PHASE1_DITHER_NTC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_PHASE1_DITHER_NTC]

//>> GET_[CPMS_FLMR_PHASE1_DITHER_NTC]
static inline bool GET_CPMS_FLMR_PHASE1_DITHER_NTC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_PHASE1_DITHER_NTC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_PHASE1_DITHER_NTC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_PHASE1_DITHER_NTC]

//>> SET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_EXIT_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_CORE_UCODE_EXIT_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_EXIT_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]

//>> SET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_EXIT_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FLMR_CORE_UCODE_EXIT_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_EXIT_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]

//>> SET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FLMR_CORE_UCODE_EXIT_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.setBit<CPMS_FLMR_CORE_UCODE_EXIT_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_EXIT_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]

//>> CLEAR_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FLMR_CORE_UCODE_EXIT_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FLMR_CORE_UCODE_EXIT_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_EXIT_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]

//>> GET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FLMR_CORE_UCODE_EXIT_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FLMR_CORE_UCODE_EXIT_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_EXIT_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]

//>> GET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]
static inline bool GET_CPMS_FLMR_CORE_UCODE_EXIT_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FLMR_RW, CPMS_FLMR_WO_CLEAR, CPMS_FLMR_WO_OR));
#endif
    return i_data.getBit<CPMS_FLMR_CORE_UCODE_EXIT_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FLMR_CORE_UCODE_EXIT_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FLMR_CORE_UCODE_EXIT_DISABLE]

//>> PREP_[CPMS_WPCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_WPCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_WPCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_WPCR]

//>> GET_[CPMS_WPCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_WPCR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_WPCR;
#endif
    return fapi2::getScom(i_target, CPMS_WPCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_WPCR]

//>> PUT_[CPMS_WPCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_WPCR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return fapi2::putScom(i_target, CPMS_WPCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_WPCR]


//>> SET_[CPMS_WPCR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_SPARE,
           CPMS_WPCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_SPARE]

//>> SET_[CPMS_WPCR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_SPARE,
           CPMS_WPCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_SPARE]

//>> GET_[CPMS_WPCR_SPARE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_SPARE,
           CPMS_WPCR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_SPARE]

//>> SET_[CPMS_WPCR_BASE_THROTTLE_INDEX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_BASE_THROTTLE_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_BASE_THROTTLE_INDEX,
           CPMS_WPCR_BASE_THROTTLE_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_BASE_THROTTLE_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_BASE_THROTTLE_INDEX]

//>> SET_[CPMS_WPCR_BASE_THROTTLE_INDEX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_BASE_THROTTLE_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_BASE_THROTTLE_INDEX,
           CPMS_WPCR_BASE_THROTTLE_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_BASE_THROTTLE_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_BASE_THROTTLE_INDEX]

//>> GET_[CPMS_WPCR_BASE_THROTTLE_INDEX]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_BASE_THROTTLE_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_BASE_THROTTLE_INDEX,
           CPMS_WPCR_BASE_THROTTLE_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_BASE_THROTTLE_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_BASE_THROTTLE_INDEX]

//>> SET_[CPMS_WPCR_INTERVAL_PROXY_TARGET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_INTERVAL_PROXY_TARGET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_INTERVAL_PROXY_TARGET,
           CPMS_WPCR_INTERVAL_PROXY_TARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_INTERVAL_PROXY_TARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_INTERVAL_PROXY_TARGET]

//>> SET_[CPMS_WPCR_INTERVAL_PROXY_TARGET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_INTERVAL_PROXY_TARGET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_INTERVAL_PROXY_TARGET,
           CPMS_WPCR_INTERVAL_PROXY_TARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_INTERVAL_PROXY_TARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_INTERVAL_PROXY_TARGET]

//>> GET_[CPMS_WPCR_INTERVAL_PROXY_TARGET]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_INTERVAL_PROXY_TARGET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_INTERVAL_PROXY_TARGET,
           CPMS_WPCR_INTERVAL_PROXY_TARGET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_INTERVAL_PROXY_TARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_INTERVAL_PROXY_TARGET]

//>> SET_[CPMS_WPCR_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_SPARE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_SPARE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_SPARE2]

//>> SET_[CPMS_WPCR_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_SPARE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_SPARE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_SPARE2]

//>> SET_[CPMS_WPCR_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_SPARE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.setBit<CPMS_WPCR_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPCR_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_SPARE2]

//>> CLEAR_[CPMS_WPCR_SPARE2]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPCR_SPARE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.clearBit<CPMS_WPCR_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPCR_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPCR_SPARE2]

//>> GET_[CPMS_WPCR_SPARE2]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_SPARE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_SPARE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_SPARE2]

//>> GET_[CPMS_WPCR_SPARE2]
static inline bool GET_CPMS_WPCR_SPARE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.getBit<CPMS_WPCR_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPCR_SPARE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_SPARE2]

//>> SET_[CPMS_WPCR_PROXY_THRESH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PROXY_THRESH_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PROXY_THRESH_SELECT,
           CPMS_WPCR_PROXY_THRESH_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_PROXY_THRESH_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PROXY_THRESH_SELECT]

//>> SET_[CPMS_WPCR_PROXY_THRESH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PROXY_THRESH_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PROXY_THRESH_SELECT,
           CPMS_WPCR_PROXY_THRESH_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_PROXY_THRESH_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PROXY_THRESH_SELECT]

//>> GET_[CPMS_WPCR_PROXY_THRESH_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_PROXY_THRESH_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_PROXY_THRESH_SELECT,
           CPMS_WPCR_PROXY_THRESH_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_PROXY_THRESH_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PROXY_THRESH_SELECT]

//>> SET_[CPMS_WPCR_PROXY_CARRYOUT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PROXY_CARRYOUT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PROXY_CARRYOUT_SEL,
           CPMS_WPCR_PROXY_CARRYOUT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_PROXY_CARRYOUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PROXY_CARRYOUT_SEL]

//>> SET_[CPMS_WPCR_PROXY_CARRYOUT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PROXY_CARRYOUT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PROXY_CARRYOUT_SEL,
           CPMS_WPCR_PROXY_CARRYOUT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_PROXY_CARRYOUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PROXY_CARRYOUT_SEL]

//>> GET_[CPMS_WPCR_PROXY_CARRYOUT_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_PROXY_CARRYOUT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_PROXY_CARRYOUT_SEL,
           CPMS_WPCR_PROXY_CARRYOUT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_PROXY_CARRYOUT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PROXY_CARRYOUT_SEL]

//>> SET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_FTX_SAT_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_FTX_SAT_MAX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]

//>> SET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_FTX_SAT_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_FTX_SAT_MAX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]

//>> SET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_FTX_SAT_MAX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.setBit<CPMS_WPCR_PITCH_FTX_SAT_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]

//>> CLEAR_[CPMS_WPCR_PITCH_FTX_SAT_MAX]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPCR_PITCH_FTX_SAT_MAX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.clearBit<CPMS_WPCR_PITCH_FTX_SAT_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPCR_PITCH_FTX_SAT_MAX]

//>> GET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_PITCH_FTX_SAT_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_PITCH_FTX_SAT_MAX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]

//>> GET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]
static inline bool GET_CPMS_WPCR_PITCH_FTX_SAT_MAX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.getBit<CPMS_WPCR_PITCH_FTX_SAT_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_FTX_SAT_MAX]

//>> SET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_FTX_SAT_MIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_FTX_SAT_MIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]

//>> SET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_FTX_SAT_MIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_FTX_SAT_MIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]

//>> SET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_FTX_SAT_MIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.setBit<CPMS_WPCR_PITCH_FTX_SAT_MIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]

//>> CLEAR_[CPMS_WPCR_PITCH_FTX_SAT_MIN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPCR_PITCH_FTX_SAT_MIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.clearBit<CPMS_WPCR_PITCH_FTX_SAT_MIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPCR_PITCH_FTX_SAT_MIN]

//>> GET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_PITCH_FTX_SAT_MIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_PITCH_FTX_SAT_MIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]

//>> GET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]
static inline bool GET_CPMS_WPCR_PITCH_FTX_SAT_MIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.getBit<CPMS_WPCR_PITCH_FTX_SAT_MIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPCR_PITCH_FTX_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_FTX_SAT_MIN]

//>> SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_ACCERR_SAT_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_ACCERR_SAT_MAX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]

//>> SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_ACCERR_SAT_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_ACCERR_SAT_MAX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]

//>> SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_ACCERR_SAT_MAX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.setBit<CPMS_WPCR_PITCH_ACCERR_SAT_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]

//>> CLEAR_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPCR_PITCH_ACCERR_SAT_MAX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.clearBit<CPMS_WPCR_PITCH_ACCERR_SAT_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]

//>> GET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_PITCH_ACCERR_SAT_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_PITCH_ACCERR_SAT_MAX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]

//>> GET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]
static inline bool GET_CPMS_WPCR_PITCH_ACCERR_SAT_MAX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.getBit<CPMS_WPCR_PITCH_ACCERR_SAT_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_ACCERR_SAT_MAX]

//>> SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_ACCERR_SAT_MIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_ACCERR_SAT_MIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]

//>> SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_ACCERR_SAT_MIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_ACCERR_SAT_MIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]

//>> SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_ACCERR_SAT_MIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.setBit<CPMS_WPCR_PITCH_ACCERR_SAT_MIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]

//>> CLEAR_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPCR_PITCH_ACCERR_SAT_MIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.clearBit<CPMS_WPCR_PITCH_ACCERR_SAT_MIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]

//>> GET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_PITCH_ACCERR_SAT_MIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_PITCH_ACCERR_SAT_MIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]

//>> GET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]
static inline bool GET_CPMS_WPCR_PITCH_ACCERR_SAT_MIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.getBit<CPMS_WPCR_PITCH_ACCERR_SAT_MIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPCR_PITCH_ACCERR_SAT_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_ACCERR_SAT_MIN]

//>> SET_[CPMS_WPCR_PITCH_APP_SATURATED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_APP_SATURATED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_APP_SATURATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_PITCH_APP_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_APP_SATURATED]

//>> SET_[CPMS_WPCR_PITCH_APP_SATURATED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_APP_SATURATED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_PITCH_APP_SATURATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_PITCH_APP_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_APP_SATURATED]

//>> SET_[CPMS_WPCR_PITCH_APP_SATURATED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_PITCH_APP_SATURATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.setBit<CPMS_WPCR_PITCH_APP_SATURATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPCR_PITCH_APP_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_PITCH_APP_SATURATED]

//>> CLEAR_[CPMS_WPCR_PITCH_APP_SATURATED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPCR_PITCH_APP_SATURATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.clearBit<CPMS_WPCR_PITCH_APP_SATURATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPCR_PITCH_APP_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPCR_PITCH_APP_SATURATED]

//>> GET_[CPMS_WPCR_PITCH_APP_SATURATED]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_PITCH_APP_SATURATED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_PITCH_APP_SATURATED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_PITCH_APP_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_APP_SATURATED]

//>> GET_[CPMS_WPCR_PITCH_APP_SATURATED]
static inline bool GET_CPMS_WPCR_PITCH_APP_SATURATED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.getBit<CPMS_WPCR_PITCH_APP_SATURATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPCR_PITCH_APP_SATURATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_PITCH_APP_SATURATED]

//>> SET_[CPMS_WPCR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_STOP_STATE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPCR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_STOP_STATE_OCCURRED]

//>> SET_[CPMS_WPCR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_STOP_STATE_OCCURRED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.insertFromRight<CPMS_WPCR_STOP_STATE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPCR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_STOP_STATE_OCCURRED]

//>> SET_[CPMS_WPCR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPCR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.setBit<CPMS_WPCR_STOP_STATE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPCR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPCR_STOP_STATE_OCCURRED]

//>> CLEAR_[CPMS_WPCR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPCR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return o_data.clearBit<CPMS_WPCR_STOP_STATE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPCR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPCR_STOP_STATE_OCCURRED]

//>> GET_[CPMS_WPCR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPCR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.extractToRight<CPMS_WPCR_STOP_STATE_OCCURRED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPCR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_STOP_STATE_OCCURRED]

//>> GET_[CPMS_WPCR_STOP_STATE_OCCURRED]
static inline bool GET_CPMS_WPCR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPCR));
#endif
    return i_data.getBit<CPMS_WPCR_STOP_STATE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPCR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPCR_STOP_STATE_OCCURRED]

//>> PREP_[EC_LS_LSU_HOLD_OUT_REG8]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_LS_LSU_HOLD_OUT_REG8(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG8;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_LS_LSU_HOLD_OUT_REG8]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_LS_LSU_HOLD_OUT_REG8(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG8;
#endif
    return fapi2::getScom(i_target, EC_LS_LSU_HOLD_OUT_REG8, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8]

//>> PUT_[EC_LS_LSU_HOLD_OUT_REG8]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_LS_LSU_HOLD_OUT_REG8(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return fapi2::putScom(i_target, EC_LS_LSU_HOLD_OUT_REG8, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_LS_LSU_HOLD_OUT_REG8]


//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG8));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT]

//>> PREP_[EC_PC_PMU_SPRCOR_CORE_FUSES]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_PMU_SPRCOR_CORE_FUSES(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_PMU_SPRCOR_CORE_FUSES;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_PMU_SPRCOR_CORE_FUSES]

//>> GET_[EC_PC_PMU_SPRCOR_CORE_FUSES]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_PMU_SPRCOR_CORE_FUSES(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_PMU_SPRCOR_CORE_FUSES;
#endif
    return fapi2::getScom(i_target, EC_PC_PMU_SPRCOR_CORE_FUSES, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_CORE_FUSES]

//>> PUT_[EC_PC_PMU_SPRCOR_CORE_FUSES]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_PMU_SPRCOR_CORE_FUSES(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_CORE_FUSES));
#endif
    return fapi2::putScom(i_target, EC_PC_PMU_SPRCOR_CORE_FUSES, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_PMU_SPRCOR_CORE_FUSES]


//>> SET_[EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_CORE_FUSES));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS]

//>> SET_[EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_CORE_FUSES));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS]

//>> SET_[EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_CORE_FUSES));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS]

//>> CLEAR_[EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_CORE_FUSES));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS]

//>> GET_[EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_CORE_FUSES));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS]

//>> GET_[EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS]
static inline bool GET_EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_CORE_FUSES));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS]

//>> SET_[EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_CORE_FUSES));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL,
           EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL]

//>> SET_[EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_CORE_FUSES));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL,
           EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL]

//>> GET_[EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_CORE_FUSES));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL,
           EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL]

//>> SET_[EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_CORE_FUSES));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS]

//>> SET_[EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_CORE_FUSES));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS]

//>> SET_[EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_CORE_FUSES));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS]

//>> CLEAR_[EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_CORE_FUSES));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS]

//>> GET_[EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_CORE_FUSES));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS]

//>> GET_[EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS]
static inline bool GET_EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_CORE_FUSES));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS]

//>> PREP_[EC_PC_SPURR_FREQ_REF]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_SPURR_FREQ_REF(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SPURR_FREQ_REF;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_SPURR_FREQ_REF]

//>> GET_[EC_PC_SPURR_FREQ_REF]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_SPURR_FREQ_REF(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SPURR_FREQ_REF;
#endif
    return fapi2::getScom(i_target, EC_PC_SPURR_FREQ_REF, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_SPURR_FREQ_REF]

//>> PUT_[EC_PC_SPURR_FREQ_REF]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_SPURR_FREQ_REF(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_SPURR_FREQ_REF));
#endif
    return fapi2::putScom(i_target, EC_PC_SPURR_FREQ_REF, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_SPURR_FREQ_REF]


//>> SET_[EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_SPURR_FREQ_REF));
#endif
    return o_data.insertFromRight<EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE,
           EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE]

//>> SET_[EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_SPURR_FREQ_REF));
#endif
    return o_data.insertFromRight<EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE,
           EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE]

//>> GET_[EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_SPURR_FREQ_REF));
#endif
    return i_data.extractToRight<EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE,
           EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE]

//>> PREP_[EC_PC_TOD_SYNC001]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TOD_SYNC001(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TOD_SYNC001;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_TOD_SYNC001]

//>> GET_[EC_PC_TOD_SYNC001]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TOD_SYNC001(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TOD_SYNC001;
#endif
    return fapi2::getScom(i_target, EC_PC_TOD_SYNC001, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_TOD_SYNC001]

//>> PUT_[EC_PC_TOD_SYNC001]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TOD_SYNC001(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC001));
#endif
    return fapi2::putScom(i_target, EC_PC_TOD_SYNC001, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_TOD_SYNC001]


//>> SET_[EC_PC_TOD_SYNC001_TOD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC001_TOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC001));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC001_TOD,
           EC_PC_TOD_SYNC001_TOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TOD_SYNC001_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TOD_SYNC001_TOD]

//>> SET_[EC_PC_TOD_SYNC001_TOD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC001_TOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC001));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC001_TOD,
           EC_PC_TOD_SYNC001_TOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TOD_SYNC001_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TOD_SYNC001_TOD]

//>> GET_[EC_PC_TOD_SYNC001_TOD]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TOD_SYNC001_TOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC001));
#endif
    return i_data.extractToRight<EC_PC_TOD_SYNC001_TOD,
           EC_PC_TOD_SYNC001_TOD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TOD_SYNC001_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TOD_SYNC001_TOD]

//>> SET_[EC_PC_TOD_SYNC001_CHIP_TOD_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC001_CHIP_TOD_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC001));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC001_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC001_CHIP_TOD_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TOD_SYNC001_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TOD_SYNC001_CHIP_TOD_STATUS]

//>> SET_[EC_PC_TOD_SYNC001_CHIP_TOD_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC001_CHIP_TOD_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC001));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC001_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC001_CHIP_TOD_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TOD_SYNC001_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TOD_SYNC001_CHIP_TOD_STATUS]

//>> GET_[EC_PC_TOD_SYNC001_CHIP_TOD_STATUS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TOD_SYNC001_CHIP_TOD_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC001));
#endif
    return i_data.extractToRight<EC_PC_TOD_SYNC001_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC001_CHIP_TOD_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TOD_SYNC001_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TOD_SYNC001_CHIP_TOD_STATUS]

//>> PREP_[EC_PC_TOD_SYNC110]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TOD_SYNC110(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TOD_SYNC110;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_TOD_SYNC110]

//>> GET_[EC_PC_TOD_SYNC110]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TOD_SYNC110(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TOD_SYNC110;
#endif
    return fapi2::getScom(i_target, EC_PC_TOD_SYNC110, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_TOD_SYNC110]

//>> PUT_[EC_PC_TOD_SYNC110]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TOD_SYNC110(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC110));
#endif
    return fapi2::putScom(i_target, EC_PC_TOD_SYNC110, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_TOD_SYNC110]


//>> SET_[EC_PC_TOD_SYNC110_TOD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC110_TOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC110));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC110_TOD,
           EC_PC_TOD_SYNC110_TOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TOD_SYNC110_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TOD_SYNC110_TOD]

//>> SET_[EC_PC_TOD_SYNC110_TOD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC110_TOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC110));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC110_TOD,
           EC_PC_TOD_SYNC110_TOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TOD_SYNC110_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TOD_SYNC110_TOD]

//>> GET_[EC_PC_TOD_SYNC110_TOD]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TOD_SYNC110_TOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC110));
#endif
    return i_data.extractToRight<EC_PC_TOD_SYNC110_TOD,
           EC_PC_TOD_SYNC110_TOD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TOD_SYNC110_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TOD_SYNC110_TOD]

//>> SET_[EC_PC_TOD_SYNC110_CHIP_TOD_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC110_CHIP_TOD_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC110));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC110_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC110_CHIP_TOD_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TOD_SYNC110_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TOD_SYNC110_CHIP_TOD_STATUS]

//>> SET_[EC_PC_TOD_SYNC110_CHIP_TOD_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC110_CHIP_TOD_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC110));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC110_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC110_CHIP_TOD_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TOD_SYNC110_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TOD_SYNC110_CHIP_TOD_STATUS]

//>> GET_[EC_PC_TOD_SYNC110_CHIP_TOD_STATUS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TOD_SYNC110_CHIP_TOD_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC110));
#endif
    return i_data.extractToRight<EC_PC_TOD_SYNC110_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC110_CHIP_TOD_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TOD_SYNC110_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TOD_SYNC110_CHIP_TOD_STATUS]

//>> PREP_[EC_PC_TRACE1_TR_TR0_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TRACE1_TR_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE1_TR_TR0_CONFIG_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_TRACE1_TR_TR0_CONFIG_3]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TRACE1_TR_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE1_TR_TR0_CONFIG_3;
#endif
    return fapi2::getScom(i_target, EC_PC_TRACE1_TR_TR0_CONFIG_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_3]

//>> PUT_[EC_PC_TRACE1_TR_TR0_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TRACE1_TR_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_3));
#endif
    return fapi2::putScom(i_target, EC_PC_TRACE1_TR_TR0_CONFIG_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_TRACE1_TR_TR0_CONFIG_3]


//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_3_C,
           EC_PC_TRACE1_TR_TR0_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_3_C]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_3_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_3_C,
           EC_PC_TRACE1_TR_TR0_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_3_C]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_3));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_3_C,
           EC_PC_TRACE1_TR_TR0_CONFIG_3_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_3_C]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_3_D,
           EC_PC_TRACE1_TR_TR0_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_3_D]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_3_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_3_D,
           EC_PC_TRACE1_TR_TR0_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_3_D]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_3));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_3_D,
           EC_PC_TRACE1_TR_TR0_CONFIG_3_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_3_D]

//>> PREP_[L2TRA_TR0_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2TRA_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR0_CONFIG_5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2TRA_TR0_CONFIG_5]

//>> GET_[L2TRA_TR0_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2TRA_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR0_CONFIG_5;
#endif
    return fapi2::getScom(i_target, L2TRA_TR0_CONFIG_5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_5]

//>> PUT_[L2TRA_TR0_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2TRA_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_5));
#endif
    return fapi2::putScom(i_target, L2TRA_TR0_CONFIG_5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2TRA_TR0_CONFIG_5]


//>> SET_[L2TRA_TR0_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_5_C,
           L2TRA_TR0_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_5_C]

//>> SET_[L2TRA_TR0_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_5_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_5_C,
           L2TRA_TR0_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_5_C]

//>> GET_[L2TRA_TR0_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_5));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_5_C,
           L2TRA_TR0_CONFIG_5_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_5_C]

//>> SET_[L2TRA_TR0_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_5_D,
           L2TRA_TR0_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_5_D]

//>> SET_[L2TRA_TR0_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_5_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_5_D,
           L2TRA_TR0_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_5_D]

//>> GET_[L2TRA_TR0_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_5));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_5_D,
           L2TRA_TR0_CONFIG_5_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_5_D]

//>> PREP_[L3_MISC_L3CERRS_ERR_INJ_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_ERR_INJ_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_ERR_INJ_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_ERR_INJ_REG]

//>> GET_[L3_MISC_L3CERRS_ERR_INJ_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_ERR_INJ_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_ERR_INJ_REG;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_ERR_INJ_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_ERR_INJ_REG]

//>> PUT_[L3_MISC_L3CERRS_ERR_INJ_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_ERR_INJ_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_ERR_INJ_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_ERR_INJ_REG]


//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ]

//>> CLEAR_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ]

//>> GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ]

//>> GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ]
static inline bool GET_L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ]

//>> CLEAR_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ]

//>> GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ]

//>> GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ]
static inline bool GET_L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE,
           L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE,
           L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE]

//>> GET_[L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE,
           L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ]

//>> CLEAR_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ]

//>> GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ]

//>> GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ]
static inline bool GET_L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ]

//>> CLEAR_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ]

//>> GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ]

//>> GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ]
static inline bool GET_L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE]

//>> CLEAR_[L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE]

//>> GET_[L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE]

//>> GET_[L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE]
static inline bool GET_L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ]

//>> CLEAR_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ]

//>> GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ]

//>> GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ]
static inline bool GET_L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ]

//>> SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ]

//>> CLEAR_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ]

//>> GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ]

//>> GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ]
static inline bool GET_L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_ERR_INJ_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ]

//>> PREP_[L3_MISC_L3CERRS_MODE_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_MODE_REG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_MODE_REG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_MODE_REG0]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_MODE_REG0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_MODE_REG0;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_MODE_REG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0]

//>> PUT_[L3_MISC_L3CERRS_MODE_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_MODE_REG0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_MODE_REG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_MODE_REG0]


//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG,
           L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG,
           L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG,
           L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV,
           L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV,
           L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV,
           L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV,
           L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV,
           L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV,
           L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN,
           L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN,
           L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN,
           L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG,
           L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG,
           L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG,
           L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG,
           L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG,
           L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG,
           L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG0));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG]

//>> PREP_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR;
#endif
    return fapi2::getScom(i_target, NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR]

//>> PUT_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return fapi2::putScom(i_target, NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR]


//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR,
           NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR]

//>> PREP_[NC_NCCHTM_NCCHTSC_HTM_TRIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCCHTM_NCCHTSC_HTM_TRIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCCHTM_NCCHTSC_HTM_TRIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NC_NCCHTM_NCCHTSC_HTM_TRIG]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCCHTM_NCCHTSC_HTM_TRIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCCHTM_NCCHTSC_HTM_TRIG;
#endif
    return fapi2::getScom(i_target, NC_NCCHTM_NCCHTSC_HTM_TRIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG]

//>> PUT_[NC_NCCHTM_NCCHTSC_HTM_TRIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCCHTM_NCCHTSC_HTM_TRIG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return fapi2::putScom(i_target, NC_NCCHTM_NCCHTSC_HTM_TRIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NC_NCCHTM_NCCHTSC_HTM_TRIG]


//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_START]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_START]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_START]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_START]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_START]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_START(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_TRIG_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_START]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_TRIG_START]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_TRIG_START(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_TRIG_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_TRIG_START]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_START]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_TRIG_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_START,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_START]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_START]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_TRIG_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_TRIG_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_START]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE,
           NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE,
           NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_TRIG));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE,
           NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE]

//>> PREP_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0]

//>> PUT_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0]


//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID,
           NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID]

//>> PREP_[QME_CIIR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_CIIR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_CIIR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_CIIR]

//>> GET_[QME_CIIR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_CIIR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_CIIR;
#endif
    return fapi2::getScom(i_target, QME_CIIR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_CIIR]

//>> PUT_[QME_CIIR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_CIIR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_CIIR));
#endif
    return fapi2::putScom(i_target, QME_CIIR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_CIIR]


//>> SET_[QME_CIIR_MSGSND_INTR_INJECT]
static inline fapi2::buffer<uint64_t>& SET_QME_CIIR_MSGSND_INTR_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CIIR));
#endif
    return o_data.insertFromRight<QME_CIIR_MSGSND_INTR_INJECT,
           QME_CIIR_MSGSND_INTR_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CIIR_MSGSND_INTR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CIIR_MSGSND_INTR_INJECT]

//>> SET_[QME_CIIR_MSGSND_INTR_INJECT]
static inline fapi2::buffer<uint64_t>& SET_QME_CIIR_MSGSND_INTR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CIIR));
#endif
    return o_data.insertFromRight<QME_CIIR_MSGSND_INTR_INJECT,
           QME_CIIR_MSGSND_INTR_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CIIR_MSGSND_INTR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CIIR_MSGSND_INTR_INJECT]

//>> GET_[QME_CIIR_MSGSND_INTR_INJECT]
static inline fapi2::buffer<uint64_t>& GET_QME_CIIR_MSGSND_INTR_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CIIR));
#endif
    return i_data.extractToRight<QME_CIIR_MSGSND_INTR_INJECT,
           QME_CIIR_MSGSND_INTR_INJECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CIIR_MSGSND_INTR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CIIR_MSGSND_INTR_INJECT]

//>> SET_[QME_CIIR_MSGSNDU_INTR_INJECT]
static inline fapi2::buffer<uint64_t>& SET_QME_CIIR_MSGSNDU_INTR_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CIIR));
#endif
    return o_data.insertFromRight<QME_CIIR_MSGSNDU_INTR_INJECT,
           QME_CIIR_MSGSNDU_INTR_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CIIR_MSGSNDU_INTR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CIIR_MSGSNDU_INTR_INJECT]

//>> SET_[QME_CIIR_MSGSNDU_INTR_INJECT]
static inline fapi2::buffer<uint64_t>& SET_QME_CIIR_MSGSNDU_INTR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CIIR));
#endif
    return o_data.insertFromRight<QME_CIIR_MSGSNDU_INTR_INJECT,
           QME_CIIR_MSGSNDU_INTR_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CIIR_MSGSNDU_INTR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CIIR_MSGSNDU_INTR_INJECT]

//>> GET_[QME_CIIR_MSGSNDU_INTR_INJECT]
static inline fapi2::buffer<uint64_t>& GET_QME_CIIR_MSGSNDU_INTR_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CIIR));
#endif
    return i_data.extractToRight<QME_CIIR_MSGSNDU_INTR_INJECT,
           QME_CIIR_MSGSNDU_INTR_INJECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CIIR_MSGSNDU_INTR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CIIR_MSGSNDU_INTR_INJECT]

//>> PREP_[QME_RMOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_RMOR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RMOR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_RMOR]

//>> GET_[QME_RMOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_RMOR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RMOR;
#endif
    return fapi2::getScom(i_target, QME_RMOR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_RMOR]

//>> PUT_[QME_RMOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_RMOR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return fapi2::putScom(i_target, QME_RMOR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_RMOR]


//>> SET_[QME_RMOR_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_RMOR_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return o_data.insertFromRight<QME_RMOR_DATA,
           QME_RMOR_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_RMOR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RMOR_DATA]

//>> SET_[QME_RMOR_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_RMOR_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return o_data.insertFromRight<QME_RMOR_DATA,
           QME_RMOR_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_RMOR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RMOR_DATA]

//>> GET_[QME_RMOR_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_RMOR_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return i_data.extractToRight<QME_RMOR_DATA,
           QME_RMOR_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_RMOR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RMOR_DATA]

//>> SET_[QME_RMOR_URMOR_SELECT]
static inline fapi2::buffer<uint64_t>& SET_QME_RMOR_URMOR_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return o_data.insertFromRight<QME_RMOR_URMOR_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_RMOR_URMOR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RMOR_URMOR_SELECT]

//>> SET_[QME_RMOR_URMOR_SELECT]
static inline fapi2::buffer<uint64_t>& SET_QME_RMOR_URMOR_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return o_data.insertFromRight<QME_RMOR_URMOR_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_RMOR_URMOR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RMOR_URMOR_SELECT]

//>> SET_[QME_RMOR_URMOR_SELECT]
static inline fapi2::buffer<uint64_t>& SET_QME_RMOR_URMOR_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return o_data.setBit<QME_RMOR_URMOR_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_RMOR_URMOR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RMOR_URMOR_SELECT]

//>> CLEAR_[QME_RMOR_URMOR_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_RMOR_URMOR_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return o_data.clearBit<QME_RMOR_URMOR_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_RMOR_URMOR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_RMOR_URMOR_SELECT]

//>> GET_[QME_RMOR_URMOR_SELECT]
static inline fapi2::buffer<uint64_t>& GET_QME_RMOR_URMOR_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return i_data.extractToRight<QME_RMOR_URMOR_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_RMOR_URMOR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RMOR_URMOR_SELECT]

//>> GET_[QME_RMOR_URMOR_SELECT]
static inline bool GET_QME_RMOR_URMOR_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RMOR));
#endif
    return i_data.getBit<QME_RMOR_URMOR_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_RMOR_URMOR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RMOR_URMOR_SELECT]

//>> PREP_[QME_SCR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCR_RW]

//>> GET_[QME_SCR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCR_RW(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCR_RW;
#endif
    return fapi2::getScom(i_target, QME_SCR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCR_RW]

//>> PUT_[QME_SCR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCR_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCR_RW, QME_SCR_WO_CLEAR, QME_SCR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_SCR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCR_RW]

//>> PREP_[QME_SCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCR_WO_CLEAR]

//>> GET_[QME_SCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, QME_SCR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCR_WO_CLEAR]

//>> PUT_[QME_SCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCR_RW, QME_SCR_WO_CLEAR, QME_SCR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_SCR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCR_WO_CLEAR]

//>> PREP_[QME_SCR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCR_WO_OR]

//>> GET_[QME_SCR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCR_WO_OR;
#endif
    return fapi2::getScom(i_target, QME_SCR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCR_WO_OR]

//>> PUT_[QME_SCR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCR_RW, QME_SCR_WO_CLEAR, QME_SCR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_SCR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCR_WO_OR]


//>> SET_[QME_SCR_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_SCR_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCR_RW, QME_SCR_WO_CLEAR, QME_SCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_SCR_DATA,
           QME_SCR_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SCR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCR_DATA]

//>> SET_[QME_SCR_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_SCR_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCR_RW, QME_SCR_WO_CLEAR, QME_SCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_SCR_DATA,
           QME_SCR_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SCR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCR_DATA]

//>> GET_[QME_SCR_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_SCR_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCR_RW, QME_SCR_WO_CLEAR, QME_SCR_WO_OR));
#endif
    return i_data.extractToRight<QME_SCR_DATA,
           QME_SCR_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SCR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCR_DATA]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
