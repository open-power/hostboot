/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/eq/reg00001.H $           */
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

#ifndef __EQ_REG00001_H_
#define __EQ_REG00001_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> PREP_[EPS_THERM_WSUB2_ERR_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_THERM_WSUB2_ERR_STATUS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB2_ERR_STATUS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_THERM_WSUB2_ERR_STATUS_REG]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_THERM_WSUB2_ERR_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB2_ERR_STATUS_REG;
#endif
    return fapi2::getScom(i_target, EPS_THERM_WSUB2_ERR_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG]

//>> PUT_[EPS_THERM_WSUB2_ERR_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_THERM_WSUB2_ERR_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return fapi2::putScom(i_target, EPS_THERM_WSUB2_ERR_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_THERM_WSUB2_ERR_STATUS_REG]


//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT,
           EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]

//>> SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.setBit<EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]

//>> CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return o_data.clearBit<EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]

//>> GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]
static inline bool GET_EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_ERR_STATUS_REG));
#endif
    return i_data.getBit<EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED]

//>> PREP_[OPCG_CAPT3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OPCG_CAPT3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_CAPT3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[OPCG_CAPT3]

//>> GET_[OPCG_CAPT3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OPCG_CAPT3(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_CAPT3;
#endif
    return fapi2::getScom(i_target, OPCG_CAPT3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[OPCG_CAPT3]

//>> PUT_[OPCG_CAPT3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OPCG_CAPT3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return fapi2::putScom(i_target, OPCG_CAPT3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[OPCG_CAPT3]


//>> SET_[OPCG_CAPT3_07EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_07EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_07EVEN,
           OPCG_CAPT3_07EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT3_07EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_07EVEN]

//>> SET_[OPCG_CAPT3_07EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_07EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_07EVEN,
           OPCG_CAPT3_07EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT3_07EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_07EVEN]

//>> GET_[OPCG_CAPT3_07EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_07EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_07EVEN,
           OPCG_CAPT3_07EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT3_07EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_07EVEN]

//>> SET_[OPCG_CAPT3_07ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_07ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_07ODD,
           OPCG_CAPT3_07ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT3_07ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_07ODD]

//>> SET_[OPCG_CAPT3_07ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_07ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_07ODD,
           OPCG_CAPT3_07ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT3_07ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_07ODD]

//>> GET_[OPCG_CAPT3_07ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_07ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_07ODD,
           OPCG_CAPT3_07ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT3_07ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_07ODD]

//>> SET_[OPCG_CAPT3_08EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_08EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_08EVEN,
           OPCG_CAPT3_08EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT3_08EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_08EVEN]

//>> SET_[OPCG_CAPT3_08EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_08EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_08EVEN,
           OPCG_CAPT3_08EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT3_08EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_08EVEN]

//>> GET_[OPCG_CAPT3_08EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_08EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_08EVEN,
           OPCG_CAPT3_08EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT3_08EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_08EVEN]

//>> SET_[OPCG_CAPT3_08ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_08ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_08ODD,
           OPCG_CAPT3_08ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT3_08ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_08ODD]

//>> SET_[OPCG_CAPT3_08ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_08ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_08ODD,
           OPCG_CAPT3_08ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT3_08ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_08ODD]

//>> GET_[OPCG_CAPT3_08ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_08ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_08ODD,
           OPCG_CAPT3_08ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT3_08ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_08ODD]

//>> SET_[OPCG_CAPT3_09EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_09EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_09EVEN,
           OPCG_CAPT3_09EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT3_09EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_09EVEN]

//>> SET_[OPCG_CAPT3_09EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_09EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_09EVEN,
           OPCG_CAPT3_09EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT3_09EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_09EVEN]

//>> GET_[OPCG_CAPT3_09EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_09EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_09EVEN,
           OPCG_CAPT3_09EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT3_09EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_09EVEN]

//>> SET_[OPCG_CAPT3_09ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_09ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_09ODD,
           OPCG_CAPT3_09ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT3_09ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_09ODD]

//>> SET_[OPCG_CAPT3_09ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_09ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_09ODD,
           OPCG_CAPT3_09ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT3_09ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_09ODD]

//>> GET_[OPCG_CAPT3_09ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_09ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_09ODD,
           OPCG_CAPT3_09ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT3_09ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_09ODD]

//>> SET_[OPCG_CAPT3_10EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_10EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_10EVEN,
           OPCG_CAPT3_10EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT3_10EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_10EVEN]

//>> SET_[OPCG_CAPT3_10EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_10EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_10EVEN,
           OPCG_CAPT3_10EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT3_10EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_10EVEN]

//>> GET_[OPCG_CAPT3_10EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_10EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_10EVEN,
           OPCG_CAPT3_10EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT3_10EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_10EVEN]

//>> SET_[OPCG_CAPT3_10ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_10ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_10ODD,
           OPCG_CAPT3_10ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT3_10ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_10ODD]

//>> SET_[OPCG_CAPT3_10ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_10ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_10ODD,
           OPCG_CAPT3_10ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT3_10ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_10ODD]

//>> GET_[OPCG_CAPT3_10ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_10ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_10ODD,
           OPCG_CAPT3_10ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT3_10ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_10ODD]

//>> SET_[OPCG_CAPT3_11EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_11EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_11EVEN,
           OPCG_CAPT3_11EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT3_11EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_11EVEN]

//>> SET_[OPCG_CAPT3_11EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_11EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_11EVEN,
           OPCG_CAPT3_11EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT3_11EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_11EVEN]

//>> GET_[OPCG_CAPT3_11EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_11EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_11EVEN,
           OPCG_CAPT3_11EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT3_11EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_11EVEN]

//>> SET_[OPCG_CAPT3_11ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_11ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_11ODD,
           OPCG_CAPT3_11ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT3_11ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_11ODD]

//>> SET_[OPCG_CAPT3_11ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_11ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_11ODD,
           OPCG_CAPT3_11ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT3_11ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_11ODD]

//>> GET_[OPCG_CAPT3_11ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_11ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_11ODD,
           OPCG_CAPT3_11ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT3_11ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_11ODD]

//>> SET_[OPCG_CAPT3_12EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_12EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_12EVEN,
           OPCG_CAPT3_12EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT3_12EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_12EVEN]

//>> SET_[OPCG_CAPT3_12EVEN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_12EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_12EVEN,
           OPCG_CAPT3_12EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT3_12EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_12EVEN]

//>> GET_[OPCG_CAPT3_12EVEN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_12EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_12EVEN,
           OPCG_CAPT3_12EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT3_12EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_12EVEN]

//>> SET_[OPCG_CAPT3_12ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_12ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_12ODD,
           OPCG_CAPT3_12ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_CAPT3_12ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_12ODD]

//>> SET_[OPCG_CAPT3_12ODD]
static inline fapi2::buffer<uint64_t>& SET_OPCG_CAPT3_12ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return o_data.insertFromRight<OPCG_CAPT3_12ODD,
           OPCG_CAPT3_12ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_CAPT3_12ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_CAPT3_12ODD]

//>> GET_[OPCG_CAPT3_12ODD]
static inline fapi2::buffer<uint64_t>& GET_OPCG_CAPT3_12ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_CAPT3));
#endif
    return i_data.extractToRight<OPCG_CAPT3_12ODD,
           OPCG_CAPT3_12ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_CAPT3_12ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_CAPT3_12ODD]

//>> PREP_[QME_EIPR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_EIPR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EIPR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_EIPR_RW]

//>> GET_[QME_EIPR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_EIPR_RW(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EIPR_RW;
#endif
    return fapi2::getScom(i_target, QME_EIPR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_EIPR_RW]

//>> PUT_[QME_EIPR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_EIPR_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_EIPR_RW, QME_EIPR_WO_CLEAR, QME_EIPR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_EIPR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_EIPR_RW]

//>> PREP_[QME_EIPR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_EIPR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EIPR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_EIPR_WO_CLEAR]

//>> GET_[QME_EIPR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_EIPR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EIPR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, QME_EIPR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_EIPR_WO_CLEAR]

//>> PUT_[QME_EIPR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_EIPR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_EIPR_RW, QME_EIPR_WO_CLEAR, QME_EIPR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_EIPR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_EIPR_WO_CLEAR]

//>> PREP_[QME_EIPR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_EIPR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EIPR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_EIPR_WO_OR]

//>> GET_[QME_EIPR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_EIPR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EIPR_WO_OR;
#endif
    return fapi2::getScom(i_target, QME_EIPR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_EIPR_WO_OR]

//>> PUT_[QME_EIPR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_EIPR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_EIPR_RW, QME_EIPR_WO_CLEAR, QME_EIPR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_EIPR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_EIPR_WO_OR]


//>> SET_[QME_EIPR_INTERRUPT_POLARITY]
static inline fapi2::buffer<uint64_t>& SET_QME_EIPR_INTERRUPT_POLARITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EIPR_RW, QME_EIPR_WO_CLEAR, QME_EIPR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EIPR_INTERRUPT_POLARITY,
           QME_EIPR_INTERRUPT_POLARITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EIPR_INTERRUPT_POLARITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EIPR_INTERRUPT_POLARITY]

//>> SET_[QME_EIPR_INTERRUPT_POLARITY]
static inline fapi2::buffer<uint64_t>& SET_QME_EIPR_INTERRUPT_POLARITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EIPR_RW, QME_EIPR_WO_CLEAR, QME_EIPR_WO_OR));
#endif
    return o_data.insertFromRight<QME_EIPR_INTERRUPT_POLARITY,
           QME_EIPR_INTERRUPT_POLARITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EIPR_INTERRUPT_POLARITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EIPR_INTERRUPT_POLARITY]

//>> GET_[QME_EIPR_INTERRUPT_POLARITY]
static inline fapi2::buffer<uint64_t>& GET_QME_EIPR_INTERRUPT_POLARITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EIPR_RW, QME_EIPR_WO_CLEAR, QME_EIPR_WO_OR));
#endif
    return i_data.extractToRight<QME_EIPR_INTERRUPT_POLARITY,
           QME_EIPR_INTERRUPT_POLARITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EIPR_INTERRUPT_POLARITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EIPR_INTERRUPT_POLARITY]

//>> PREP_[QME_LFIRMASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_LFIRMASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_LFIRMASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_LFIRMASK_RW]

//>> GET_[QME_LFIRMASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_LFIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_LFIRMASK_RW;
#endif
    return fapi2::getScom(i_target, QME_LFIRMASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_LFIRMASK_RW]

//>> PUT_[QME_LFIRMASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_LFIRMASK_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_LFIRMASK_RW, QME_LFIRMASK_WO_AND, QME_LFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_LFIRMASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_LFIRMASK_RW]

//>> PREP_[QME_LFIRMASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_LFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_LFIRMASK_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_LFIRMASK_WO_AND]

//>> GET_[QME_LFIRMASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_LFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_LFIRMASK_WO_AND;
#endif
    return fapi2::getScom(i_target, QME_LFIRMASK_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_LFIRMASK_WO_AND]

//>> PUT_[QME_LFIRMASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_LFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_LFIRMASK_RW, QME_LFIRMASK_WO_AND, QME_LFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_LFIRMASK_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_LFIRMASK_WO_AND]

//>> PREP_[QME_LFIRMASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_LFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_LFIRMASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_LFIRMASK_WO_OR]

//>> GET_[QME_LFIRMASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_LFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_LFIRMASK_WO_OR;
#endif
    return fapi2::getScom(i_target, QME_LFIRMASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_LFIRMASK_WO_OR]

//>> PUT_[QME_LFIRMASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_LFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_LFIRMASK_RW, QME_LFIRMASK_WO_AND, QME_LFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_LFIRMASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_LFIRMASK_WO_OR]


//>> SET_[QME_LFIRMASK_FIR_MASK]
static inline fapi2::buffer<uint64_t>& SET_QME_LFIRMASK_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_LFIRMASK_RW, QME_LFIRMASK_WO_AND, QME_LFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<QME_LFIRMASK_FIR_MASK,
           QME_LFIRMASK_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_LFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_LFIRMASK_FIR_MASK]

//>> SET_[QME_LFIRMASK_FIR_MASK]
static inline fapi2::buffer<uint64_t>& SET_QME_LFIRMASK_FIR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_LFIRMASK_RW, QME_LFIRMASK_WO_AND, QME_LFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<QME_LFIRMASK_FIR_MASK,
           QME_LFIRMASK_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_LFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_LFIRMASK_FIR_MASK]

//>> GET_[QME_LFIRMASK_FIR_MASK]
static inline fapi2::buffer<uint64_t>& GET_QME_LFIRMASK_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_LFIRMASK_RW, QME_LFIRMASK_WO_AND, QME_LFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<QME_LFIRMASK_FIR_MASK,
           QME_LFIRMASK_FIR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_LFIRMASK_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_LFIRMASK_FIR_MASK]

//>> PREP_[QME_SCDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCDR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCDR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCDR]

//>> GET_[QME_SCDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCDR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCDR;
#endif
    return fapi2::getScom(i_target, QME_SCDR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCDR]

//>> PUT_[QME_SCDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCDR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return fapi2::putScom(i_target, QME_SCDR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCDR]


//>> SET_[QME_SCDR_STOP_GATED]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_STOP_GATED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_STOP_GATED,
           QME_SCDR_STOP_GATED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCDR_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_STOP_GATED]

//>> SET_[QME_SCDR_STOP_GATED]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_STOP_GATED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_STOP_GATED,
           QME_SCDR_STOP_GATED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCDR_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_STOP_GATED]

//>> GET_[QME_SCDR_STOP_GATED]
static inline fapi2::buffer<uint64_t>& GET_QME_SCDR_STOP_GATED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return i_data.extractToRight<QME_SCDR_STOP_GATED,
           QME_SCDR_STOP_GATED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCDR_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCDR_STOP_GATED]

//>> SET_[QME_SCDR_STOP_TRANSITION_C0]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_STOP_TRANSITION_C0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_STOP_TRANSITION_C0,
           QME_SCDR_STOP_TRANSITION_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCDR_STOP_TRANSITION_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_STOP_TRANSITION_C0]

//>> SET_[QME_SCDR_STOP_TRANSITION_C0]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_STOP_TRANSITION_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_STOP_TRANSITION_C0,
           QME_SCDR_STOP_TRANSITION_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCDR_STOP_TRANSITION_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_STOP_TRANSITION_C0]

//>> GET_[QME_SCDR_STOP_TRANSITION_C0]
static inline fapi2::buffer<uint64_t>& GET_QME_SCDR_STOP_TRANSITION_C0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return i_data.extractToRight<QME_SCDR_STOP_TRANSITION_C0,
           QME_SCDR_STOP_TRANSITION_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCDR_STOP_TRANSITION_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCDR_STOP_TRANSITION_C0]

//>> SET_[QME_SCDR_STOP_TRANSITION_C1]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_STOP_TRANSITION_C1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_STOP_TRANSITION_C1,
           QME_SCDR_STOP_TRANSITION_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCDR_STOP_TRANSITION_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_STOP_TRANSITION_C1]

//>> SET_[QME_SCDR_STOP_TRANSITION_C1]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_STOP_TRANSITION_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_STOP_TRANSITION_C1,
           QME_SCDR_STOP_TRANSITION_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCDR_STOP_TRANSITION_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_STOP_TRANSITION_C1]

//>> GET_[QME_SCDR_STOP_TRANSITION_C1]
static inline fapi2::buffer<uint64_t>& GET_QME_SCDR_STOP_TRANSITION_C1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return i_data.extractToRight<QME_SCDR_STOP_TRANSITION_C1,
           QME_SCDR_STOP_TRANSITION_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCDR_STOP_TRANSITION_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCDR_STOP_TRANSITION_C1]

//>> SET_[QME_SCDR_STOP_TRANSITION_C2]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_STOP_TRANSITION_C2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_STOP_TRANSITION_C2,
           QME_SCDR_STOP_TRANSITION_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCDR_STOP_TRANSITION_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_STOP_TRANSITION_C2]

//>> SET_[QME_SCDR_STOP_TRANSITION_C2]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_STOP_TRANSITION_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_STOP_TRANSITION_C2,
           QME_SCDR_STOP_TRANSITION_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCDR_STOP_TRANSITION_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_STOP_TRANSITION_C2]

//>> GET_[QME_SCDR_STOP_TRANSITION_C2]
static inline fapi2::buffer<uint64_t>& GET_QME_SCDR_STOP_TRANSITION_C2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return i_data.extractToRight<QME_SCDR_STOP_TRANSITION_C2,
           QME_SCDR_STOP_TRANSITION_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCDR_STOP_TRANSITION_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCDR_STOP_TRANSITION_C2]

//>> SET_[QME_SCDR_STOP_TRANSITION_C3]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_STOP_TRANSITION_C3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_STOP_TRANSITION_C3,
           QME_SCDR_STOP_TRANSITION_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCDR_STOP_TRANSITION_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_STOP_TRANSITION_C3]

//>> SET_[QME_SCDR_STOP_TRANSITION_C3]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_STOP_TRANSITION_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_STOP_TRANSITION_C3,
           QME_SCDR_STOP_TRANSITION_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCDR_STOP_TRANSITION_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_STOP_TRANSITION_C3]

//>> GET_[QME_SCDR_STOP_TRANSITION_C3]
static inline fapi2::buffer<uint64_t>& GET_QME_SCDR_STOP_TRANSITION_C3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return i_data.extractToRight<QME_SCDR_STOP_TRANSITION_C3,
           QME_SCDR_STOP_TRANSITION_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCDR_STOP_TRANSITION_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCDR_STOP_TRANSITION_C3]

//>> SET_[QME_SCDR_SPC_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_SPC_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_SPC_WKUP_DONE,
           QME_SCDR_SPC_WKUP_DONE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCDR_SPC_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_SPC_WKUP_DONE]

//>> SET_[QME_SCDR_SPC_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_SPC_WKUP_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_SPC_WKUP_DONE,
           QME_SCDR_SPC_WKUP_DONE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCDR_SPC_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_SPC_WKUP_DONE]

//>> GET_[QME_SCDR_SPC_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCDR_SPC_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return i_data.extractToRight<QME_SCDR_SPC_WKUP_DONE,
           QME_SCDR_SPC_WKUP_DONE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCDR_SPC_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCDR_SPC_WKUP_DONE]

//>> SET_[QME_SCDR_REQ_STOP_LEVEL_C0]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_REQ_STOP_LEVEL_C0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_REQ_STOP_LEVEL_C0,
           QME_SCDR_REQ_STOP_LEVEL_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCDR_REQ_STOP_LEVEL_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_REQ_STOP_LEVEL_C0]

//>> SET_[QME_SCDR_REQ_STOP_LEVEL_C0]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_REQ_STOP_LEVEL_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_REQ_STOP_LEVEL_C0,
           QME_SCDR_REQ_STOP_LEVEL_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCDR_REQ_STOP_LEVEL_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_REQ_STOP_LEVEL_C0]

//>> GET_[QME_SCDR_REQ_STOP_LEVEL_C0]
static inline fapi2::buffer<uint64_t>& GET_QME_SCDR_REQ_STOP_LEVEL_C0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return i_data.extractToRight<QME_SCDR_REQ_STOP_LEVEL_C0,
           QME_SCDR_REQ_STOP_LEVEL_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCDR_REQ_STOP_LEVEL_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCDR_REQ_STOP_LEVEL_C0]

//>> SET_[QME_SCDR_REQ_STOP_LEVEL_C1]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_REQ_STOP_LEVEL_C1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_REQ_STOP_LEVEL_C1,
           QME_SCDR_REQ_STOP_LEVEL_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCDR_REQ_STOP_LEVEL_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_REQ_STOP_LEVEL_C1]

//>> SET_[QME_SCDR_REQ_STOP_LEVEL_C1]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_REQ_STOP_LEVEL_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_REQ_STOP_LEVEL_C1,
           QME_SCDR_REQ_STOP_LEVEL_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCDR_REQ_STOP_LEVEL_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_REQ_STOP_LEVEL_C1]

//>> GET_[QME_SCDR_REQ_STOP_LEVEL_C1]
static inline fapi2::buffer<uint64_t>& GET_QME_SCDR_REQ_STOP_LEVEL_C1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return i_data.extractToRight<QME_SCDR_REQ_STOP_LEVEL_C1,
           QME_SCDR_REQ_STOP_LEVEL_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCDR_REQ_STOP_LEVEL_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCDR_REQ_STOP_LEVEL_C1]

//>> SET_[QME_SCDR_REQ_STOP_LEVEL_C2]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_REQ_STOP_LEVEL_C2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_REQ_STOP_LEVEL_C2,
           QME_SCDR_REQ_STOP_LEVEL_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCDR_REQ_STOP_LEVEL_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_REQ_STOP_LEVEL_C2]

//>> SET_[QME_SCDR_REQ_STOP_LEVEL_C2]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_REQ_STOP_LEVEL_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_REQ_STOP_LEVEL_C2,
           QME_SCDR_REQ_STOP_LEVEL_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCDR_REQ_STOP_LEVEL_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_REQ_STOP_LEVEL_C2]

//>> GET_[QME_SCDR_REQ_STOP_LEVEL_C2]
static inline fapi2::buffer<uint64_t>& GET_QME_SCDR_REQ_STOP_LEVEL_C2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return i_data.extractToRight<QME_SCDR_REQ_STOP_LEVEL_C2,
           QME_SCDR_REQ_STOP_LEVEL_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCDR_REQ_STOP_LEVEL_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCDR_REQ_STOP_LEVEL_C2]

//>> SET_[QME_SCDR_REQ_STOP_LEVEL_C3]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_REQ_STOP_LEVEL_C3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_REQ_STOP_LEVEL_C3,
           QME_SCDR_REQ_STOP_LEVEL_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCDR_REQ_STOP_LEVEL_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_REQ_STOP_LEVEL_C3]

//>> SET_[QME_SCDR_REQ_STOP_LEVEL_C3]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_REQ_STOP_LEVEL_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_REQ_STOP_LEVEL_C3,
           QME_SCDR_REQ_STOP_LEVEL_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCDR_REQ_STOP_LEVEL_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_REQ_STOP_LEVEL_C3]

//>> GET_[QME_SCDR_REQ_STOP_LEVEL_C3]
static inline fapi2::buffer<uint64_t>& GET_QME_SCDR_REQ_STOP_LEVEL_C3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return i_data.extractToRight<QME_SCDR_REQ_STOP_LEVEL_C3,
           QME_SCDR_REQ_STOP_LEVEL_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCDR_REQ_STOP_LEVEL_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCDR_REQ_STOP_LEVEL_C3]

//>> SET_[QME_SCDR_REG_WKUP_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_REG_WKUP_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_REG_WKUP_REQUESTED,
           QME_SCDR_REG_WKUP_REQUESTED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCDR_REG_WKUP_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_REG_WKUP_REQUESTED]

//>> SET_[QME_SCDR_REG_WKUP_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_REG_WKUP_REQUESTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_REG_WKUP_REQUESTED,
           QME_SCDR_REG_WKUP_REQUESTED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCDR_REG_WKUP_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_REG_WKUP_REQUESTED]

//>> GET_[QME_SCDR_REG_WKUP_REQUESTED]
static inline fapi2::buffer<uint64_t>& GET_QME_SCDR_REG_WKUP_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return i_data.extractToRight<QME_SCDR_REG_WKUP_REQUESTED,
           QME_SCDR_REG_WKUP_REQUESTED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCDR_REG_WKUP_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCDR_REG_WKUP_REQUESTED]

//>> SET_[QME_SCDR_SPC_WKUP_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_SPC_WKUP_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_SPC_WKUP_REQUESTED,
           QME_SCDR_SPC_WKUP_REQUESTED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCDR_SPC_WKUP_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_SPC_WKUP_REQUESTED]

//>> SET_[QME_SCDR_SPC_WKUP_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_SPC_WKUP_REQUESTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_SPC_WKUP_REQUESTED,
           QME_SCDR_SPC_WKUP_REQUESTED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCDR_SPC_WKUP_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_SPC_WKUP_REQUESTED]

//>> GET_[QME_SCDR_SPC_WKUP_REQUESTED]
static inline fapi2::buffer<uint64_t>& GET_QME_SCDR_SPC_WKUP_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return i_data.extractToRight<QME_SCDR_SPC_WKUP_REQUESTED,
           QME_SCDR_SPC_WKUP_REQUESTED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCDR_SPC_WKUP_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCDR_SPC_WKUP_REQUESTED]

//>> SET_[QME_SCDR_SELF_SAVE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_SELF_SAVE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_SELF_SAVE_ACTIVE,
           QME_SCDR_SELF_SAVE_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCDR_SELF_SAVE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_SELF_SAVE_ACTIVE]

//>> SET_[QME_SCDR_SELF_SAVE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_SELF_SAVE_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_SELF_SAVE_ACTIVE,
           QME_SCDR_SELF_SAVE_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCDR_SELF_SAVE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_SELF_SAVE_ACTIVE]

//>> GET_[QME_SCDR_SELF_SAVE_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCDR_SELF_SAVE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return i_data.extractToRight<QME_SCDR_SELF_SAVE_ACTIVE,
           QME_SCDR_SELF_SAVE_ACTIVE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCDR_SELF_SAVE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCDR_SELF_SAVE_ACTIVE]

//>> SET_[QME_SCDR_SELF_RESTORE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_SELF_RESTORE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_SELF_RESTORE_ACTIVE,
           QME_SCDR_SELF_RESTORE_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCDR_SELF_RESTORE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_SELF_RESTORE_ACTIVE]

//>> SET_[QME_SCDR_SELF_RESTORE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_SELF_RESTORE_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_SELF_RESTORE_ACTIVE,
           QME_SCDR_SELF_RESTORE_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCDR_SELF_RESTORE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_SELF_RESTORE_ACTIVE]

//>> GET_[QME_SCDR_SELF_RESTORE_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCDR_SELF_RESTORE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return i_data.extractToRight<QME_SCDR_SELF_RESTORE_ACTIVE,
           QME_SCDR_SELF_RESTORE_ACTIVE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCDR_SELF_RESTORE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCDR_SELF_RESTORE_ACTIVE]

//>> SET_[QME_SCDR_ACT_STOP_LEVEL_C0]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_ACT_STOP_LEVEL_C0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_ACT_STOP_LEVEL_C0,
           QME_SCDR_ACT_STOP_LEVEL_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCDR_ACT_STOP_LEVEL_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_ACT_STOP_LEVEL_C0]

//>> SET_[QME_SCDR_ACT_STOP_LEVEL_C0]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_ACT_STOP_LEVEL_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_ACT_STOP_LEVEL_C0,
           QME_SCDR_ACT_STOP_LEVEL_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCDR_ACT_STOP_LEVEL_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_ACT_STOP_LEVEL_C0]

//>> GET_[QME_SCDR_ACT_STOP_LEVEL_C0]
static inline fapi2::buffer<uint64_t>& GET_QME_SCDR_ACT_STOP_LEVEL_C0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return i_data.extractToRight<QME_SCDR_ACT_STOP_LEVEL_C0,
           QME_SCDR_ACT_STOP_LEVEL_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCDR_ACT_STOP_LEVEL_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCDR_ACT_STOP_LEVEL_C0]

//>> SET_[QME_SCDR_ACT_STOP_LEVEL_C1]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_ACT_STOP_LEVEL_C1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_ACT_STOP_LEVEL_C1,
           QME_SCDR_ACT_STOP_LEVEL_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCDR_ACT_STOP_LEVEL_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_ACT_STOP_LEVEL_C1]

//>> SET_[QME_SCDR_ACT_STOP_LEVEL_C1]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_ACT_STOP_LEVEL_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_ACT_STOP_LEVEL_C1,
           QME_SCDR_ACT_STOP_LEVEL_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCDR_ACT_STOP_LEVEL_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_ACT_STOP_LEVEL_C1]

//>> GET_[QME_SCDR_ACT_STOP_LEVEL_C1]
static inline fapi2::buffer<uint64_t>& GET_QME_SCDR_ACT_STOP_LEVEL_C1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return i_data.extractToRight<QME_SCDR_ACT_STOP_LEVEL_C1,
           QME_SCDR_ACT_STOP_LEVEL_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCDR_ACT_STOP_LEVEL_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCDR_ACT_STOP_LEVEL_C1]

//>> SET_[QME_SCDR_ACT_STOP_LEVEL_C2]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_ACT_STOP_LEVEL_C2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_ACT_STOP_LEVEL_C2,
           QME_SCDR_ACT_STOP_LEVEL_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCDR_ACT_STOP_LEVEL_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_ACT_STOP_LEVEL_C2]

//>> SET_[QME_SCDR_ACT_STOP_LEVEL_C2]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_ACT_STOP_LEVEL_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_ACT_STOP_LEVEL_C2,
           QME_SCDR_ACT_STOP_LEVEL_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCDR_ACT_STOP_LEVEL_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_ACT_STOP_LEVEL_C2]

//>> GET_[QME_SCDR_ACT_STOP_LEVEL_C2]
static inline fapi2::buffer<uint64_t>& GET_QME_SCDR_ACT_STOP_LEVEL_C2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return i_data.extractToRight<QME_SCDR_ACT_STOP_LEVEL_C2,
           QME_SCDR_ACT_STOP_LEVEL_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCDR_ACT_STOP_LEVEL_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCDR_ACT_STOP_LEVEL_C2]

//>> SET_[QME_SCDR_ACT_STOP_LEVEL_C3]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_ACT_STOP_LEVEL_C3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_ACT_STOP_LEVEL_C3,
           QME_SCDR_ACT_STOP_LEVEL_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCDR_ACT_STOP_LEVEL_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_ACT_STOP_LEVEL_C3]

//>> SET_[QME_SCDR_ACT_STOP_LEVEL_C3]
static inline fapi2::buffer<uint64_t>& SET_QME_SCDR_ACT_STOP_LEVEL_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return o_data.insertFromRight<QME_SCDR_ACT_STOP_LEVEL_C3,
           QME_SCDR_ACT_STOP_LEVEL_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCDR_ACT_STOP_LEVEL_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCDR_ACT_STOP_LEVEL_C3]

//>> GET_[QME_SCDR_ACT_STOP_LEVEL_C3]
static inline fapi2::buffer<uint64_t>& GET_QME_SCDR_ACT_STOP_LEVEL_C3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCDR));
#endif
    return i_data.extractToRight<QME_SCDR_ACT_STOP_LEVEL_C3,
           QME_SCDR_ACT_STOP_LEVEL_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCDR_ACT_STOP_LEVEL_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCDR_ACT_STOP_LEVEL_C3]

//>> PREP_[QME_SCOM_XIDBGPRO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCOM_XIDBGPRO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XIDBGPRO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCOM_XIDBGPRO]

//>> GET_[QME_SCOM_XIDBGPRO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCOM_XIDBGPRO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XIDBGPRO;
#endif
    return fapi2::getScom(i_target, QME_SCOM_XIDBGPRO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO]

//>> PUT_[QME_SCOM_XIDBGPRO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCOM_XIDBGPRO(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return fapi2::putScom(i_target, QME_SCOM_XIDBGPRO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCOM_XIDBGPRO]


//>> SET_[QME_SCOM_XIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_HS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_HS]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_HS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_HS]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_HS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.setBit<QME_SCOM_XIDBGPRO_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_HS]

//>> CLEAR_[QME_SCOM_XIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIDBGPRO_XSR_HS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.clearBit<QME_SCOM_XIDBGPRO_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIDBGPRO_XSR_HS]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_HS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_HS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_HS]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_HS]
static inline bool GET_QME_SCOM_XIDBGPRO_XSR_HS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.getBit<QME_SCOM_XIDBGPRO_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_HS]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_HC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_HC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_HC,
           QME_SCOM_XIDBGPRO_XSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_HC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_HC]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_HC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_HC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_HC,
           QME_SCOM_XIDBGPRO_XSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_HC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_HC]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_HC]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_HC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_HC,
           QME_SCOM_XIDBGPRO_XSR_HC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_HC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_HC]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_HCP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_HCP]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_HCP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_HCP]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_HCP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.setBit<QME_SCOM_XIDBGPRO_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_HCP]

//>> CLEAR_[QME_SCOM_XIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIDBGPRO_XSR_HCP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.clearBit<QME_SCOM_XIDBGPRO_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIDBGPRO_XSR_HCP]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_HCP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_HCP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_HCP]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_HCP]
static inline bool GET_QME_SCOM_XIDBGPRO_XSR_HCP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.getBit<QME_SCOM_XIDBGPRO_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_HCP]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_RIP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_RIP]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_RIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_RIP]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_RIP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.setBit<QME_SCOM_XIDBGPRO_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_RIP]

//>> CLEAR_[QME_SCOM_XIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIDBGPRO_XSR_RIP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.clearBit<QME_SCOM_XIDBGPRO_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIDBGPRO_XSR_RIP]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_RIP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_RIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_RIP]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_RIP]
static inline bool GET_QME_SCOM_XIDBGPRO_XSR_RIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.getBit<QME_SCOM_XIDBGPRO_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_RIP]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_SIP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_SIP]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_SIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_SIP]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_SIP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.setBit<QME_SCOM_XIDBGPRO_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_SIP]

//>> CLEAR_[QME_SCOM_XIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIDBGPRO_XSR_SIP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.clearBit<QME_SCOM_XIDBGPRO_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIDBGPRO_XSR_SIP]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_SIP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_SIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_SIP]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_SIP]
static inline bool GET_QME_SCOM_XIDBGPRO_XSR_SIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.getBit<QME_SCOM_XIDBGPRO_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_SIP]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_TRAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_TRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_TRAP]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_TRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_TRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_TRAP]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_TRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.setBit<QME_SCOM_XIDBGPRO_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_TRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_TRAP]

//>> CLEAR_[QME_SCOM_XIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIDBGPRO_XSR_TRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.clearBit<QME_SCOM_XIDBGPRO_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_TRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIDBGPRO_XSR_TRAP]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_TRAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_TRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_TRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_TRAP]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_TRAP]
static inline bool GET_QME_SCOM_XIDBGPRO_XSR_TRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.getBit<QME_SCOM_XIDBGPRO_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_TRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_TRAP]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_IAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_IAC]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_IAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_IAC]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_IAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.setBit<QME_SCOM_XIDBGPRO_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_IAC]

//>> CLEAR_[QME_SCOM_XIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIDBGPRO_XSR_IAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.clearBit<QME_SCOM_XIDBGPRO_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIDBGPRO_XSR_IAC]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_IAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_IAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_IAC]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_IAC]
static inline bool GET_QME_SCOM_XIDBGPRO_XSR_IAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.getBit<QME_SCOM_XIDBGPRO_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_IAC]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_SIB]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_SIB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_SIB,
           QME_SCOM_XIDBGPRO_XSR_SIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_SIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_SIB]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_SIB]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_SIB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_SIB,
           QME_SCOM_XIDBGPRO_XSR_SIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_SIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_SIB]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_SIB]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_SIB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_SIB,
           QME_SCOM_XIDBGPRO_XSR_SIB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_SIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_SIB]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_RDAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_RDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_RDAC]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_RDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_RDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_RDAC]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_RDAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.setBit<QME_SCOM_XIDBGPRO_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_RDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_RDAC]

//>> CLEAR_[QME_SCOM_XIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIDBGPRO_XSR_RDAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.clearBit<QME_SCOM_XIDBGPRO_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_RDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIDBGPRO_XSR_RDAC]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_RDAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_RDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_RDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_RDAC]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_RDAC]
static inline bool GET_QME_SCOM_XIDBGPRO_XSR_RDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.getBit<QME_SCOM_XIDBGPRO_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_RDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_RDAC]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_WDAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_WDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_WDAC]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_WDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_WDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_WDAC]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_WDAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.setBit<QME_SCOM_XIDBGPRO_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_WDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_WDAC]

//>> CLEAR_[QME_SCOM_XIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIDBGPRO_XSR_WDAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.clearBit<QME_SCOM_XIDBGPRO_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_WDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIDBGPRO_XSR_WDAC]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_WDAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_WDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_WDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_WDAC]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_WDAC]
static inline bool GET_QME_SCOM_XIDBGPRO_XSR_WDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.getBit<QME_SCOM_XIDBGPRO_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_WDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_WDAC]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_WS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_WS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_WS]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_WS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_WS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_WS]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_WS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.setBit<QME_SCOM_XIDBGPRO_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_WS]

//>> CLEAR_[QME_SCOM_XIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIDBGPRO_XSR_WS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.clearBit<QME_SCOM_XIDBGPRO_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIDBGPRO_XSR_WS]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_WS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_WS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_WS]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_WS]
static inline bool GET_QME_SCOM_XIDBGPRO_XSR_WS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.getBit<QME_SCOM_XIDBGPRO_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_WS]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_TRH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_TRH]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_TRH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_TRH]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_TRH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.setBit<QME_SCOM_XIDBGPRO_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_TRH]

//>> CLEAR_[QME_SCOM_XIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIDBGPRO_XSR_TRH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.clearBit<QME_SCOM_XIDBGPRO_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIDBGPRO_XSR_TRH]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_TRH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_TRH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_TRH]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_TRH]
static inline bool GET_QME_SCOM_XIDBGPRO_XSR_TRH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.getBit<QME_SCOM_XIDBGPRO_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_TRH]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_SMS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_SMS,
           QME_SCOM_XIDBGPRO_XSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_SMS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_SMS]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_SMS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_SMS,
           QME_SCOM_XIDBGPRO_XSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_SMS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_SMS]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_SMS]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_SMS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_SMS,
           QME_SCOM_XIDBGPRO_XSR_SMS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_SMS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_SMS]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_LP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_LP]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_LP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_LP]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_LP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.setBit<QME_SCOM_XIDBGPRO_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_LP]

//>> CLEAR_[QME_SCOM_XIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIDBGPRO_XSR_LP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.clearBit<QME_SCOM_XIDBGPRO_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIDBGPRO_XSR_LP]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_LP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_LP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_LP]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_LP]
static inline bool GET_QME_SCOM_XIDBGPRO_XSR_LP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.getBit<QME_SCOM_XIDBGPRO_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_LP]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_EP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_EP]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_EP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_EP]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_EP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.setBit<QME_SCOM_XIDBGPRO_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_EP]

//>> CLEAR_[QME_SCOM_XIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIDBGPRO_XSR_EP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.clearBit<QME_SCOM_XIDBGPRO_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIDBGPRO_XSR_EP]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_EP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_EP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_EP]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_EP]
static inline bool GET_QME_SCOM_XIDBGPRO_XSR_EP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.getBit<QME_SCOM_XIDBGPRO_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_EP]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_PTR]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_PTR]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_PTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.setBit<QME_SCOM_XIDBGPRO_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_PTR]

//>> CLEAR_[QME_SCOM_XIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIDBGPRO_XSR_PTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.clearBit<QME_SCOM_XIDBGPRO_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIDBGPRO_XSR_PTR]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_PTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_PTR]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_PTR]
static inline bool GET_QME_SCOM_XIDBGPRO_XSR_PTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.getBit<QME_SCOM_XIDBGPRO_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_PTR]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_ST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_ST]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_ST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_ST]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_ST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.setBit<QME_SCOM_XIDBGPRO_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_ST]

//>> CLEAR_[QME_SCOM_XIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIDBGPRO_XSR_ST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.clearBit<QME_SCOM_XIDBGPRO_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIDBGPRO_XSR_ST]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_ST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_ST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_ST]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_ST]
static inline bool GET_QME_SCOM_XIDBGPRO_XSR_ST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.getBit<QME_SCOM_XIDBGPRO_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_ST]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_MFE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_MFE]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_MFE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_MFE]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_MFE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.setBit<QME_SCOM_XIDBGPRO_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_MFE]

//>> CLEAR_[QME_SCOM_XIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIDBGPRO_XSR_MFE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.clearBit<QME_SCOM_XIDBGPRO_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIDBGPRO_XSR_MFE]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_MFE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_MFE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_MFE]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_MFE]
static inline bool GET_QME_SCOM_XIDBGPRO_XSR_MFE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.getBit<QME_SCOM_XIDBGPRO_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_MFE]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_MCS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_MCS,
           QME_SCOM_XIDBGPRO_XSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_MCS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_MCS]

//>> SET_[QME_SCOM_XIDBGPRO_XSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_XSR_MCS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_XSR_MCS,
           QME_SCOM_XIDBGPRO_XSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_MCS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_XSR_MCS]

//>> GET_[QME_SCOM_XIDBGPRO_XSR_MCS]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_XSR_MCS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_XSR_MCS,
           QME_SCOM_XIDBGPRO_XSR_MCS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_XSR_MCS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_XSR_MCS]

//>> SET_[QME_SCOM_XIDBGPRO_IAR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_IAR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_IAR,
           QME_SCOM_XIDBGPRO_IAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_IAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_IAR]

//>> SET_[QME_SCOM_XIDBGPRO_IAR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIDBGPRO_IAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return o_data.insertFromRight<QME_SCOM_XIDBGPRO_IAR,
           QME_SCOM_XIDBGPRO_IAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_IAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIDBGPRO_IAR]

//>> GET_[QME_SCOM_XIDBGPRO_IAR]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIDBGPRO_IAR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIDBGPRO));
#endif
    return i_data.extractToRight<QME_SCOM_XIDBGPRO_IAR,
           QME_SCOM_XIDBGPRO_IAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIDBGPRO_IAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIDBGPRO_IAR]

//>> PREP_[QME_SSDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SSDR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SSDR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SSDR]

//>> GET_[QME_SSDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SSDR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SSDR;
#endif
    return fapi2::getScom(i_target, QME_SSDR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SSDR]

//>> PUT_[QME_SSDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SSDR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return fapi2::putScom(i_target, QME_SSDR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SSDR]


//>> SET_[QME_SSDR_PC_UNMASKED_ATTN]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_PC_UNMASKED_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_PC_UNMASKED_ATTN,
           QME_SSDR_PC_UNMASKED_ATTN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SSDR_PC_UNMASKED_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_PC_UNMASKED_ATTN]

//>> SET_[QME_SSDR_PC_UNMASKED_ATTN]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_PC_UNMASKED_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_PC_UNMASKED_ATTN,
           QME_SSDR_PC_UNMASKED_ATTN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SSDR_PC_UNMASKED_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_PC_UNMASKED_ATTN]

//>> GET_[QME_SSDR_PC_UNMASKED_ATTN]
static inline fapi2::buffer<uint64_t>& GET_QME_SSDR_PC_UNMASKED_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return i_data.extractToRight<QME_SSDR_PC_UNMASKED_ATTN,
           QME_SSDR_PC_UNMASKED_ATTN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SSDR_PC_UNMASKED_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSDR_PC_UNMASKED_ATTN]

//>> SET_[QME_SSDR_INSTR_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_INSTR_RUNNING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_INSTR_RUNNING,
           QME_SSDR_INSTR_RUNNING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SSDR_INSTR_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_INSTR_RUNNING]

//>> SET_[QME_SSDR_INSTR_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_INSTR_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_INSTR_RUNNING,
           QME_SSDR_INSTR_RUNNING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SSDR_INSTR_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_INSTR_RUNNING]

//>> GET_[QME_SSDR_INSTR_RUNNING]
static inline fapi2::buffer<uint64_t>& GET_QME_SSDR_INSTR_RUNNING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return i_data.extractToRight<QME_SSDR_INSTR_RUNNING,
           QME_SSDR_INSTR_RUNNING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SSDR_INSTR_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSDR_INSTR_RUNNING]

//>> SET_[QME_SSDR_QME_SCSR_PM_EXIT]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_QME_SCSR_PM_EXIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_QME_SCSR_PM_EXIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SSDR_QME_SCSR_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_QME_SCSR_PM_EXIT]

//>> SET_[QME_SSDR_QME_SCSR_PM_EXIT]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_QME_SCSR_PM_EXIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_QME_SCSR_PM_EXIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SSDR_QME_SCSR_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_QME_SCSR_PM_EXIT]

//>> SET_[QME_SSDR_QME_SCSR_PM_EXIT]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_QME_SCSR_PM_EXIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.setBit<QME_SSDR_QME_SCSR_PM_EXIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SSDR_QME_SCSR_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_QME_SCSR_PM_EXIT]

//>> CLEAR_[QME_SSDR_QME_SCSR_PM_EXIT]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSDR_QME_SCSR_PM_EXIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.clearBit<QME_SSDR_QME_SCSR_PM_EXIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SSDR_QME_SCSR_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSDR_QME_SCSR_PM_EXIT]

//>> GET_[QME_SSDR_QME_SCSR_PM_EXIT]
static inline fapi2::buffer<uint64_t>& GET_QME_SSDR_QME_SCSR_PM_EXIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return i_data.extractToRight<QME_SSDR_QME_SCSR_PM_EXIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SSDR_QME_SCSR_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSDR_QME_SCSR_PM_EXIT]

//>> GET_[QME_SSDR_QME_SCSR_PM_EXIT]
static inline bool GET_QME_SSDR_QME_SCSR_PM_EXIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return i_data.getBit<QME_SSDR_QME_SCSR_PM_EXIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SSDR_QME_SCSR_PM_EXIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSDR_QME_SCSR_PM_EXIT]

//>> SET_[QME_SSDR_PM_STATE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_PM_STATE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_PM_STATE_ACTIVE,
           QME_SSDR_PM_STATE_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SSDR_PM_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_PM_STATE_ACTIVE]

//>> SET_[QME_SSDR_PM_STATE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_PM_STATE_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_PM_STATE_ACTIVE,
           QME_SSDR_PM_STATE_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SSDR_PM_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_PM_STATE_ACTIVE]

//>> GET_[QME_SSDR_PM_STATE_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_QME_SSDR_PM_STATE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return i_data.extractToRight<QME_SSDR_PM_STATE_ACTIVE,
           QME_SSDR_PM_STATE_ACTIVE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SSDR_PM_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSDR_PM_STATE_ACTIVE]

//>> SET_[QME_SSDR_PM_STATE_C0]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_PM_STATE_C0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_PM_STATE_C0,
           QME_SSDR_PM_STATE_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SSDR_PM_STATE_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_PM_STATE_C0]

//>> SET_[QME_SSDR_PM_STATE_C0]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_PM_STATE_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_PM_STATE_C0,
           QME_SSDR_PM_STATE_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SSDR_PM_STATE_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_PM_STATE_C0]

//>> GET_[QME_SSDR_PM_STATE_C0]
static inline fapi2::buffer<uint64_t>& GET_QME_SSDR_PM_STATE_C0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return i_data.extractToRight<QME_SSDR_PM_STATE_C0,
           QME_SSDR_PM_STATE_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SSDR_PM_STATE_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSDR_PM_STATE_C0]

//>> SET_[QME_SSDR_PM_STATE_C1]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_PM_STATE_C1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_PM_STATE_C1,
           QME_SSDR_PM_STATE_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SSDR_PM_STATE_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_PM_STATE_C1]

//>> SET_[QME_SSDR_PM_STATE_C1]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_PM_STATE_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_PM_STATE_C1,
           QME_SSDR_PM_STATE_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SSDR_PM_STATE_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_PM_STATE_C1]

//>> GET_[QME_SSDR_PM_STATE_C1]
static inline fapi2::buffer<uint64_t>& GET_QME_SSDR_PM_STATE_C1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return i_data.extractToRight<QME_SSDR_PM_STATE_C1,
           QME_SSDR_PM_STATE_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SSDR_PM_STATE_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSDR_PM_STATE_C1]

//>> SET_[QME_SSDR_PM_STATE_C2]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_PM_STATE_C2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_PM_STATE_C2,
           QME_SSDR_PM_STATE_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SSDR_PM_STATE_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_PM_STATE_C2]

//>> SET_[QME_SSDR_PM_STATE_C2]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_PM_STATE_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_PM_STATE_C2,
           QME_SSDR_PM_STATE_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SSDR_PM_STATE_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_PM_STATE_C2]

//>> GET_[QME_SSDR_PM_STATE_C2]
static inline fapi2::buffer<uint64_t>& GET_QME_SSDR_PM_STATE_C2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return i_data.extractToRight<QME_SSDR_PM_STATE_C2,
           QME_SSDR_PM_STATE_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SSDR_PM_STATE_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSDR_PM_STATE_C2]

//>> SET_[QME_SSDR_PM_STATE_C3]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_PM_STATE_C3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_PM_STATE_C3,
           QME_SSDR_PM_STATE_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SSDR_PM_STATE_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_PM_STATE_C3]

//>> SET_[QME_SSDR_PM_STATE_C3]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_PM_STATE_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_PM_STATE_C3,
           QME_SSDR_PM_STATE_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SSDR_PM_STATE_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_PM_STATE_C3]

//>> GET_[QME_SSDR_PM_STATE_C3]
static inline fapi2::buffer<uint64_t>& GET_QME_SSDR_PM_STATE_C3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return i_data.extractToRight<QME_SSDR_PM_STATE_C3,
           QME_SSDR_PM_STATE_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SSDR_PM_STATE_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSDR_PM_STATE_C3]

//>> SET_[QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS]

//>> SET_[QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS]

//>> SET_[QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.setBit<QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS]

//>> CLEAR_[QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.clearBit<QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS]

//>> GET_[QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS]
static inline fapi2::buffer<uint64_t>& GET_QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return i_data.extractToRight<QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS]

//>> GET_[QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS]
static inline bool GET_QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return i_data.getBit<QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSDR_QME_SCSR_BLOCK_INTR_OUTPUTS]

//>> SET_[QME_SSDR_QME_SCSR_PM_BLOCK_INTR]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_QME_SCSR_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_QME_SCSR_PM_BLOCK_INTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SSDR_QME_SCSR_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_QME_SCSR_PM_BLOCK_INTR]

//>> SET_[QME_SSDR_QME_SCSR_PM_BLOCK_INTR]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_QME_SCSR_PM_BLOCK_INTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_QME_SCSR_PM_BLOCK_INTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SSDR_QME_SCSR_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_QME_SCSR_PM_BLOCK_INTR]

//>> SET_[QME_SSDR_QME_SCSR_PM_BLOCK_INTR]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_QME_SCSR_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.setBit<QME_SSDR_QME_SCSR_PM_BLOCK_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SSDR_QME_SCSR_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_QME_SCSR_PM_BLOCK_INTR]

//>> CLEAR_[QME_SSDR_QME_SCSR_PM_BLOCK_INTR]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSDR_QME_SCSR_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.clearBit<QME_SSDR_QME_SCSR_PM_BLOCK_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SSDR_QME_SCSR_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSDR_QME_SCSR_PM_BLOCK_INTR]

//>> GET_[QME_SSDR_QME_SCSR_PM_BLOCK_INTR]
static inline fapi2::buffer<uint64_t>& GET_QME_SSDR_QME_SCSR_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return i_data.extractToRight<QME_SSDR_QME_SCSR_PM_BLOCK_INTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SSDR_QME_SCSR_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSDR_QME_SCSR_PM_BLOCK_INTR]

//>> GET_[QME_SSDR_QME_SCSR_PM_BLOCK_INTR]
static inline bool GET_QME_SSDR_QME_SCSR_PM_BLOCK_INTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return i_data.getBit<QME_SSDR_QME_SCSR_PM_BLOCK_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SSDR_QME_SCSR_PM_BLOCK_INTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSDR_QME_SCSR_PM_BLOCK_INTR]

//>> SET_[QME_SSDR_PC_DPES_INTR_PEND]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_PC_DPES_INTR_PEND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_PC_DPES_INTR_PEND,
           QME_SSDR_PC_DPES_INTR_PEND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SSDR_PC_DPES_INTR_PEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_PC_DPES_INTR_PEND]

//>> SET_[QME_SSDR_PC_DPES_INTR_PEND]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_PC_DPES_INTR_PEND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_PC_DPES_INTR_PEND,
           QME_SSDR_PC_DPES_INTR_PEND_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SSDR_PC_DPES_INTR_PEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_PC_DPES_INTR_PEND]

//>> GET_[QME_SSDR_PC_DPES_INTR_PEND]
static inline fapi2::buffer<uint64_t>& GET_QME_SSDR_PC_DPES_INTR_PEND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return i_data.extractToRight<QME_SSDR_PC_DPES_INTR_PEND,
           QME_SSDR_PC_DPES_INTR_PEND_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SSDR_PC_DPES_INTR_PEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSDR_PC_DPES_INTR_PEND]

//>> SET_[QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE]

//>> SET_[QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE]

//>> SET_[QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.setBit<QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE]

//>> CLEAR_[QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.clearBit<QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE]

//>> GET_[QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return i_data.extractToRight<QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE]

//>> GET_[QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE]
static inline bool GET_QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return i_data.getBit<QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE]

//>> SET_[QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE,
           QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE]

//>> SET_[QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return o_data.insertFromRight<QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE,
           QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE]

//>> GET_[QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE]
static inline fapi2::buffer<uint64_t>& GET_QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSDR));
#endif
    return i_data.extractToRight<QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE,
           QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSDR_QME_SSH_SRC_SAMPLED_STOP_STATE]

//>> PREP_[QME_SWHR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SWHR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SWHR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SWHR]

//>> GET_[QME_SWHR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SWHR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SWHR;
#endif
    return fapi2::getScom(i_target, QME_SWHR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SWHR]

//>> PUT_[QME_SWHR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SWHR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return fapi2::putScom(i_target, QME_SWHR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SWHR]


//>> SET_[QME_SWHR_SPC_WKUP_HISTORY_C0]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_SPC_WKUP_HISTORY_C0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_SPC_WKUP_HISTORY_C0,
           QME_SWHR_SPC_WKUP_HISTORY_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SWHR_SPC_WKUP_HISTORY_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_SPC_WKUP_HISTORY_C0]

//>> SET_[QME_SWHR_SPC_WKUP_HISTORY_C0]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_SPC_WKUP_HISTORY_C0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_SPC_WKUP_HISTORY_C0,
           QME_SWHR_SPC_WKUP_HISTORY_C0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SWHR_SPC_WKUP_HISTORY_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_SPC_WKUP_HISTORY_C0]

//>> GET_[QME_SWHR_SPC_WKUP_HISTORY_C0]
static inline fapi2::buffer<uint64_t>& GET_QME_SWHR_SPC_WKUP_HISTORY_C0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return i_data.extractToRight<QME_SWHR_SPC_WKUP_HISTORY_C0,
           QME_SWHR_SPC_WKUP_HISTORY_C0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SWHR_SPC_WKUP_HISTORY_C0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SWHR_SPC_WKUP_HISTORY_C0]

//>> SET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET,
           QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET]

//>> SET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET,
           QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET]

//>> GET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET]
static inline fapi2::buffer<uint64_t>& GET_QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return i_data.extractToRight<QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET,
           QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_SET]

//>> SET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR,
           QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR]

//>> SET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR,
           QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR]

//>> GET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR]
static inline fapi2::buffer<uint64_t>& GET_QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return i_data.extractToRight<QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR,
           QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_CLR]

//>> SET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT,
           QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT]

//>> SET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT,
           QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT]

//>> GET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT]
static inline fapi2::buffer<uint64_t>& GET_QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return i_data.extractToRight<QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT,
           QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_ACT]

//>> SET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP,
           QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP]

//>> SET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP,
           QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP]

//>> GET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP]
static inline fapi2::buffer<uint64_t>& GET_QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return i_data.extractToRight<QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP,
           QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SWHR_QME_SSH_SRC_SPC_WKUP_RECENT_DRP]

//>> SET_[QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ]

//>> SET_[QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ]

//>> SET_[QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.setBit<QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ]

//>> CLEAR_[QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.clearBit<QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ]

//>> GET_[QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& GET_QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return i_data.extractToRight<QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ]

//>> GET_[QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ]
static inline bool GET_QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return i_data.getBit<QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SWHR_QME_SPWU_OTR_SPECIAL_WKUP_REQ]

//>> SET_[QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ]

//>> SET_[QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ]

//>> SET_[QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.setBit<QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ]

//>> CLEAR_[QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.clearBit<QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ]

//>> GET_[QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& GET_QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return i_data.extractToRight<QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ]

//>> GET_[QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ]
static inline bool GET_QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return i_data.getBit<QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SWHR_QME_SPWU_FSP_SPECIAL_WKUP_REQ]

//>> SET_[QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ]

//>> SET_[QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ]

//>> SET_[QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.setBit<QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ]

//>> CLEAR_[QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.clearBit<QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ]

//>> GET_[QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& GET_QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return i_data.extractToRight<QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ]

//>> GET_[QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ]
static inline bool GET_QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return i_data.getBit<QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SWHR_QME_SPWU_OCC_SPECIAL_WKUP_REQ]

//>> SET_[QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ]

//>> SET_[QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ]

//>> SET_[QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.setBit<QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ]

//>> CLEAR_[QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.clearBit<QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ]

//>> GET_[QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ]
static inline fapi2::buffer<uint64_t>& GET_QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return i_data.extractToRight<QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ]

//>> GET_[QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ]
static inline bool GET_QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return i_data.getBit<QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SWHR_QME_SPWU_HYP_SPECIAL_WKUP_REQ]

//>> SET_[QME_SWHR_SPC_WKUP_HISTORY_C1]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_SPC_WKUP_HISTORY_C1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_SPC_WKUP_HISTORY_C1,
           QME_SWHR_SPC_WKUP_HISTORY_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SWHR_SPC_WKUP_HISTORY_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_SPC_WKUP_HISTORY_C1]

//>> SET_[QME_SWHR_SPC_WKUP_HISTORY_C1]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_SPC_WKUP_HISTORY_C1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_SPC_WKUP_HISTORY_C1,
           QME_SWHR_SPC_WKUP_HISTORY_C1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SWHR_SPC_WKUP_HISTORY_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_SPC_WKUP_HISTORY_C1]

//>> GET_[QME_SWHR_SPC_WKUP_HISTORY_C1]
static inline fapi2::buffer<uint64_t>& GET_QME_SWHR_SPC_WKUP_HISTORY_C1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return i_data.extractToRight<QME_SWHR_SPC_WKUP_HISTORY_C1,
           QME_SWHR_SPC_WKUP_HISTORY_C1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SWHR_SPC_WKUP_HISTORY_C1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SWHR_SPC_WKUP_HISTORY_C1]

//>> SET_[QME_SWHR_SPC_WKUP_HISTORY_C2]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_SPC_WKUP_HISTORY_C2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_SPC_WKUP_HISTORY_C2,
           QME_SWHR_SPC_WKUP_HISTORY_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SWHR_SPC_WKUP_HISTORY_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_SPC_WKUP_HISTORY_C2]

//>> SET_[QME_SWHR_SPC_WKUP_HISTORY_C2]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_SPC_WKUP_HISTORY_C2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_SPC_WKUP_HISTORY_C2,
           QME_SWHR_SPC_WKUP_HISTORY_C2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SWHR_SPC_WKUP_HISTORY_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_SPC_WKUP_HISTORY_C2]

//>> GET_[QME_SWHR_SPC_WKUP_HISTORY_C2]
static inline fapi2::buffer<uint64_t>& GET_QME_SWHR_SPC_WKUP_HISTORY_C2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return i_data.extractToRight<QME_SWHR_SPC_WKUP_HISTORY_C2,
           QME_SWHR_SPC_WKUP_HISTORY_C2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SWHR_SPC_WKUP_HISTORY_C2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SWHR_SPC_WKUP_HISTORY_C2]

//>> SET_[QME_SWHR_SPC_WKUP_HISTORY_C3]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_SPC_WKUP_HISTORY_C3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_SPC_WKUP_HISTORY_C3,
           QME_SWHR_SPC_WKUP_HISTORY_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SWHR_SPC_WKUP_HISTORY_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_SPC_WKUP_HISTORY_C3]

//>> SET_[QME_SWHR_SPC_WKUP_HISTORY_C3]
static inline fapi2::buffer<uint64_t>& SET_QME_SWHR_SPC_WKUP_HISTORY_C3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return o_data.insertFromRight<QME_SWHR_SPC_WKUP_HISTORY_C3,
           QME_SWHR_SPC_WKUP_HISTORY_C3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SWHR_SPC_WKUP_HISTORY_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWHR_SPC_WKUP_HISTORY_C3]

//>> GET_[QME_SWHR_SPC_WKUP_HISTORY_C3]
static inline fapi2::buffer<uint64_t>& GET_QME_SWHR_SPC_WKUP_HISTORY_C3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWHR));
#endif
    return i_data.extractToRight<QME_SWHR_SPC_WKUP_HISTORY_C3,
           QME_SWHR_SPC_WKUP_HISTORY_C3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SWHR_SPC_WKUP_HISTORY_C3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SWHR_SPC_WKUP_HISTORY_C3]

//>> PREP_[QME_SWPR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SWPR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SWPR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SWPR0]

//>> GET_[QME_SWPR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SWPR0(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SWPR0;
#endif
    return fapi2::getScom(i_target, QME_SWPR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SWPR0]

//>> PUT_[QME_SWPR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SWPR0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SWPR0));
#endif
    return fapi2::putScom(i_target, QME_SWPR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SWPR0]


//>> SET_[QME_SWPR0_BAR]
static inline fapi2::buffer<uint64_t>& SET_QME_SWPR0_BAR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWPR0));
#endif
    return o_data.insertFromRight<QME_SWPR0_BAR,
           QME_SWPR0_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SWPR0_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWPR0_BAR]

//>> SET_[QME_SWPR0_BAR]
static inline fapi2::buffer<uint64_t>& SET_QME_SWPR0_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWPR0));
#endif
    return o_data.insertFromRight<QME_SWPR0_BAR,
           QME_SWPR0_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SWPR0_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWPR0_BAR]

//>> GET_[QME_SWPR0_BAR]
static inline fapi2::buffer<uint64_t>& GET_QME_SWPR0_BAR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWPR0));
#endif
    return i_data.extractToRight<QME_SWPR0_BAR,
           QME_SWPR0_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SWPR0_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SWPR0_BAR]

//>> SET_[QME_SWPR0_SIZE]
static inline fapi2::buffer<uint64_t>& SET_QME_SWPR0_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWPR0));
#endif
    return o_data.insertFromRight<QME_SWPR0_SIZE,
           QME_SWPR0_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SWPR0_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWPR0_SIZE]

//>> SET_[QME_SWPR0_SIZE]
static inline fapi2::buffer<uint64_t>& SET_QME_SWPR0_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWPR0));
#endif
    return o_data.insertFromRight<QME_SWPR0_SIZE,
           QME_SWPR0_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SWPR0_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SWPR0_SIZE]

//>> GET_[QME_SWPR0_SIZE]
static inline fapi2::buffer<uint64_t>& GET_QME_SWPR0_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SWPR0));
#endif
    return i_data.extractToRight<QME_SWPR0_SIZE,
           QME_SWPR0_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SWPR0_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SWPR0_SIZE]

//>> PREP_[QME_TBR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_TBR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_TBR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_TBR]

//>> GET_[QME_TBR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_TBR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_TBR;
#endif
    return fapi2::getScom(i_target, QME_TBR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_TBR]

//>> PUT_[QME_TBR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_TBR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_TBR));
#endif
    return fapi2::putScom(i_target, QME_TBR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_TBR]


//>> SET_[QME_TBR_TIMEBASE]
static inline fapi2::buffer<uint64_t>& SET_QME_TBR_TIMEBASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TBR));
#endif
    return o_data.insertFromRight<QME_TBR_TIMEBASE,
           QME_TBR_TIMEBASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_TBR_TIMEBASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TBR_TIMEBASE]

//>> SET_[QME_TBR_TIMEBASE]
static inline fapi2::buffer<uint64_t>& SET_QME_TBR_TIMEBASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TBR));
#endif
    return o_data.insertFromRight<QME_TBR_TIMEBASE,
           QME_TBR_TIMEBASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_TBR_TIMEBASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TBR_TIMEBASE]

//>> GET_[QME_TBR_TIMEBASE]
static inline fapi2::buffer<uint64_t>& GET_QME_TBR_TIMEBASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TBR));
#endif
    return i_data.extractToRight<QME_TBR_TIMEBASE,
           QME_TBR_TIMEBASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_TBR_TIMEBASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TBR_TIMEBASE]

//>> SET_[QME_TBR_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_QME_TBR_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TBR));
#endif
    return o_data.insertFromRight<QME_TBR_CYCLES,
           QME_TBR_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_TBR_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TBR_CYCLES]

//>> SET_[QME_TBR_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_QME_TBR_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TBR));
#endif
    return o_data.insertFromRight<QME_TBR_CYCLES,
           QME_TBR_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_TBR_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_TBR_CYCLES]

//>> GET_[QME_TBR_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_QME_TBR_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_TBR));
#endif
    return i_data.extractToRight<QME_TBR_CYCLES,
           QME_TBR_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_TBR_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_TBR_CYCLES]

//>> PREP_[SCAN32]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCAN32(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN32;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCAN32]

//>> GET_[SCAN32]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCAN32(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN32;
#endif
    return fapi2::getScom(i_target, SCAN32, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCAN32]

//>> PUT_[SCAN32]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCAN32(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCAN32));
#endif
    return fapi2::putScom(i_target, SCAN32, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCAN32]


//>> SET_[SCAN32_SCAN32_REG]
static inline fapi2::buffer<uint64_t>& SET_SCAN32_SCAN32_REG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN32));
#endif
    return o_data.insertFromRight<SCAN32_SCAN32_REG,
           SCAN32_SCAN32_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN32_SCAN32_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN32_SCAN32_REG]

//>> SET_[SCAN32_SCAN32_REG]
static inline fapi2::buffer<uint64_t>& SET_SCAN32_SCAN32_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN32));
#endif
    return o_data.insertFromRight<SCAN32_SCAN32_REG,
           SCAN32_SCAN32_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN32_SCAN32_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN32_SCAN32_REG]

//>> GET_[SCAN32_SCAN32_REG]
static inline fapi2::buffer<uint64_t>& GET_SCAN32_SCAN32_REG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN32));
#endif
    return i_data.extractToRight<SCAN32_SCAN32_REG,
           SCAN32_SCAN32_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN32_SCAN32_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN32_SCAN32_REG]

//>> PREP_[SCAN64]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCAN64(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN64;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCAN64]

//>> GET_[SCAN64]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCAN64(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN64;
#endif
    return fapi2::getScom(i_target, SCAN64, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCAN64]

//>> PUT_[SCAN64]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCAN64(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCAN64));
#endif
    return fapi2::putScom(i_target, SCAN64, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCAN64]


//>> SET_[SCAN64_SCAN64_REG]
static inline fapi2::buffer<uint64_t>& SET_SCAN64_SCAN64_REG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN64));
#endif
    return o_data.insertFromRight<SCAN64_SCAN64_REG,
           SCAN64_SCAN64_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN64_SCAN64_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN64_SCAN64_REG]

//>> SET_[SCAN64_SCAN64_REG]
static inline fapi2::buffer<uint64_t>& SET_SCAN64_SCAN64_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN64));
#endif
    return o_data.insertFromRight<SCAN64_SCAN64_REG,
           SCAN64_SCAN64_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN64_SCAN64_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN64_SCAN64_REG]

//>> GET_[SCAN64_SCAN64_REG]
static inline fapi2::buffer<uint64_t>& GET_SCAN64_SCAN64_REG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN64));
#endif
    return i_data.extractToRight<SCAN64_SCAN64_REG,
           SCAN64_SCAN64_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN64_SCAN64_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN64_SCAN64_REG]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
