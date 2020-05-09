/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00074.H $         */
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

#ifndef __PROC_REG00074_H_
#define __PROC_REG00074_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI]

//>> GET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI]

//>> PUT_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI]

//>> PREP_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE]


//>> SET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1,
           TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1]

//>> SET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1,
           TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1]

//>> GET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1,
           TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_DMA_PIB_RCV_BUF1_REG_DATA1]

//>> PREP_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI]

//>> GET_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI]

//>> PUT_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI]

//>> PREP_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE]


//>> SET_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_CONTROL_BITS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_CONTROL_BITS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_CONTROL_BITS,
           TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_CONTROL_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_CONTROL_BITS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_CONTROL_BITS]

//>> SET_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_CONTROL_BITS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_CONTROL_BITS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_CONTROL_BITS,
           TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_CONTROL_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_CONTROL_BITS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_CONTROL_BITS]

//>> GET_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_CONTROL_BITS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_CONTROL_BITS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_CONTROL_BITS,
           TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_CONTROL_BITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_CONTROL_BITS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_CONTROL_BITS]

//>> SET_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FRONT_END_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FRONT_END_LENGTH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FRONT_END_LENGTH,
           TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FRONT_END_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FRONT_END_LENGTH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FRONT_END_LENGTH]

//>> SET_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FRONT_END_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FRONT_END_LENGTH(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FRONT_END_LENGTH,
           TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FRONT_END_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FRONT_END_LENGTH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FRONT_END_LENGTH]

//>> GET_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FRONT_END_LENGTH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FRONT_END_LENGTH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FRONT_END_LENGTH,
           TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FRONT_END_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FRONT_END_LENGTH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SHIFT_FRONT_END_LENGTH_REGISTER_FRONT_END_LENGTH]

//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0]

//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO]


//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_GENERAL_RESET_1]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_WO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP1_ERROR_RESET_1]

//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_FSI0]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_FSI0]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_FSI0]

//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_SCOMFSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_SCOMFSI0]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_SCOMFSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_SCOMFSI0]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_SCOMFSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP2_SCOMFSI0]


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_FSI0]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_FSI0]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_FSI0]

//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_SCOMFSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_SCOMFSI0]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_SCOMFSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_SCOMFSI0]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_SCOMFSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP3_SCOMFSI0]


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_FSI0]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_FSI0]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_FSI0]

//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_SCOMFSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_SCOMFSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_SCOMFSI0]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_SCOMFSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_SCOMFSI0]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_SCOMFSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MDLYR_SCOMFSI0]


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_FSI0]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_FSI0]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_FSI0]

//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_SCOMFSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_SCOMFSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_SCOMFSI0]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_SCOMFSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_SCOMFSI0]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_SCOMFSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MENP1_SCOMFSI0]


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0]

//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO]


//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_0]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_1]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_2]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_3]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_4]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_5]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_6]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MLEVP0_7]

//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0]

//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO]


//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_0]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_0]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_0]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_2,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_2]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_2,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_2]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_2,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI_A_MST_1_PORT2_ERROR_CODE_2]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FOURTH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FOURTH_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FOURTH_ERROR,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FOURTH_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FOURTH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FOURTH_ERROR]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FOURTH_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FOURTH_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FOURTH_ERROR,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FOURTH_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FOURTH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FOURTH_ERROR]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FOURTH_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FOURTH_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FOURTH_ERROR,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FOURTH_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FOURTH_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FOURTH_ERROR]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_CRC_ERROR_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_CRC_ERROR_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_CRC_ERROR_COUNT,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_CRC_ERROR_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_CRC_ERROR_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_CRC_ERROR_COUNT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_CRC_ERROR_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_CRC_ERROR_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_CRC_ERROR_COUNT,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_CRC_ERROR_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_CRC_ERROR_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_CRC_ERROR_COUNT]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_CRC_ERROR_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_CRC_ERROR_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_CRC_ERROR_COUNT,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_CRC_ERROR_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_CRC_ERROR_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_CRC_ERROR_COUNT]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG]

//>> SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG]

//>> CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG]
static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP2_HOT_PLUG_FLAG]

//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_SIC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SIC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SIC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_SIC]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SIC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SIC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SIC;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SIC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SIC]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_SIC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SIC(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SIC));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SIC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_SIC]


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_SISS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SISS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SISS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_SISS]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SISS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SISS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SISS;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SISS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SISS]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_SISS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SISS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SISS));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SISS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_SISS]


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_A_SRSIS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SRSIS0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SRSIS0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_A_SRSIS0]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_A_SRSIS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SRSIS0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SRSIS0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SRSIS0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_A_SRSIS0]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_A_SRSIS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SRSIS0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SRSIS0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SRSIS0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_A_SRSIS0]


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_B_SIC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SIC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SIC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_B_SIC]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SIC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SIC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SIC;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SIC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SIC]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_B_SIC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SIC(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SIC));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SIC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_B_SIC]


//>> PREP_[VAS_VA_EG_SCF_PGMIG3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_EG_SCF_PGMIG3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_PGMIG3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_EG_SCF_PGMIG3]

//>> GET_[VAS_VA_EG_SCF_PGMIG3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_EG_SCF_PGMIG3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_PGMIG3;
#endif
    return fapi2::getScom(i_target, VAS_VA_EG_SCF_PGMIG3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_EG_SCF_PGMIG3]

//>> PUT_[VAS_VA_EG_SCF_PGMIG3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_EG_SCF_PGMIG3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PGMIG3));
#endif
    return fapi2::putScom(i_target, VAS_VA_EG_SCF_PGMIG3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_EG_SCF_PGMIG3]


//>> PREP_[VAS_VA_EG_SCF_WCERRRPT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_EG_SCF_WCERRRPT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_WCERRRPT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_EG_SCF_WCERRRPT]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_EG_SCF_WCERRRPT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_WCERRRPT;
#endif
    return fapi2::getScom(i_target, VAS_VA_EG_SCF_WCERRRPT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT]

//>> PUT_[VAS_VA_EG_SCF_WCERRRPT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_EG_SCF_WCERRRPT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return fapi2::putScom(i_target, VAS_VA_EG_SCF_WCERRRPT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_EG_SCF_WCERRRPT]


//>> SET_[VAS_VA_EG_SCF_WCERRRPT_RESET]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_RESET]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_RESET]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_RESET]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_RESET]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_RESET]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_RESET]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_RESET]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_RESET]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_RESET]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_RESET]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT4]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT4]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT4]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT4]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT4]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT4]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT4]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT4]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT4]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT4]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT4]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT4]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT5]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT5]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT5]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT5]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT5]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT5]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT5]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT5]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT5]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT5]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT5]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT5]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT6]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT6]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT6]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT6]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT6]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT6]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT6]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT6]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT6]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT6]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT6]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT6]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT7]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT7]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT7]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT7]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT7]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT7]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT7]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT7]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT7]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT7]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT7]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT7]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT8]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT8]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT8]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT8]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT8]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT8]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT8]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT8]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT8]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT8]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT8]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT8]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT9]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT9]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT9]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT9]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT9]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT9]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT9]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT9]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT9]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT9]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT9]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT9]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT10]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT10]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT10]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT10]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT10]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT10]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT10]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT10]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT10]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT10]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT10]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT10]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT11]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT11]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT11]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT11]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT11]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT11]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT11]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT11]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT11]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT11]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT11]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT11]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT12]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT12]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT12]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT12]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT12]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT12]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT12]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT12]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT12]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT12]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT12]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT12]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT13]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT13]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT13]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT13]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT13]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT13]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT13]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT13]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT13]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT13]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT13]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT13]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT14]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT14]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT14]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT14]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT14]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT14]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT14]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT14]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT14]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT14]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT14]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT14]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT15]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT15]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT15]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT15]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT15]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT15]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT15]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT15]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT15]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT15]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT15]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT15]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT16]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT16]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT16]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT16]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT16]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT16]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT16]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT16]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT16]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT16]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT16]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT16]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT17]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT17]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT17]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT17]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT17]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT17]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT17]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT17]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT17]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT17]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT17]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT17]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT18]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT18]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT18]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT18]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT18]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT18]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT18]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT18]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT18]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT18]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT18]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT18]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT19]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT19]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT19]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT19]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT19]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT19]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT19]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT19]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT19]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT19]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT19]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT19]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT20]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT20]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT20]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT20]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT20]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT20]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT20]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT20]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT20]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT20]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT20]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT20]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT21]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT21]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT21]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT21]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT21]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT21]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT21]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT21]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT21]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT21]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT21]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT21]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT22]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT22]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT22]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT22]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT22]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT22]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT22]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT22]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT22]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT22]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT22]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT22]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT23]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_WCERRRPT_BIT23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT23]

//>> SET_[VAS_VA_EG_SCF_WCERRRPT_BIT23]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_WCERRRPT_BIT23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_WCERRRPT_BIT23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_EG_SCF_WCERRRPT_BIT23]

//>> CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT23]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_WCERRRPT_BIT23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_WCERRRPT_BIT23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_EG_SCF_WCERRRPT_BIT23]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT23]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_WCERRRPT_BIT23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_WCERRRPT_BIT23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT23]

//>> GET_[VAS_VA_EG_SCF_WCERRRPT_BIT23]
static inline bool GET_VAS_VA_EG_SCF_WCERRRPT_BIT23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_WCERRRPT));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_WCERRRPT_BIT23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_EG_SCF_WCERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_EG_SCF_WCERRRPT_BIT23]

//>> PREP_[VAS_VA_RG_SCF_WRMON0CMP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WRMON0CMP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON0CMP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_RG_SCF_WRMON0CMP]

//>> GET_[VAS_VA_RG_SCF_WRMON0CMP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WRMON0CMP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON0CMP;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WRMON0CMP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_RG_SCF_WRMON0CMP]

//>> PUT_[VAS_VA_RG_SCF_WRMON0CMP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WRMON0CMP(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WRMON0CMP));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WRMON0CMP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_RG_SCF_WRMON0CMP]


//>> PREP_[VAS_VA_RG_SCF_WRMON1WID]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WRMON1WID(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON1WID;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_RG_SCF_WRMON1WID]

//>> GET_[VAS_VA_RG_SCF_WRMON1WID]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WRMON1WID(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON1WID;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WRMON1WID, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_RG_SCF_WRMON1WID]

//>> PUT_[VAS_VA_RG_SCF_WRMON1WID]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WRMON1WID(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WRMON1WID));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WRMON1WID, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_RG_SCF_WRMON1WID]


//>> PREP_[VAS_VA_RG_SCF_WRMON4BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WRMON4BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON4BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_RG_SCF_WRMON4BAR]

//>> GET_[VAS_VA_RG_SCF_WRMON4BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WRMON4BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON4BAR;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WRMON4BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_RG_SCF_WRMON4BAR]

//>> PUT_[VAS_VA_RG_SCF_WRMON4BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WRMON4BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WRMON4BAR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WRMON4BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_RG_SCF_WRMON4BAR]



//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
