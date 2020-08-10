/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00059.H $         */
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

#ifndef __PROC_REG00059_H_
#define __PROC_REG00059_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI]

//>> PUT_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI]

//>> PREP_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE]

//>> PREP_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO]

//>> PUT_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO]


//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY]

//>> CLEAR_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY]
static inline bool GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DATA_OUT_PARITY]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE]

//>> CLEAR_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE]
static inline bool GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SBE]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP]

//>> CLEAR_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP]
static inline bool GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_REQ_RESET_FR_SP]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG]

//>> CLEAR_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG]
static inline bool GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_DEQUEUED_EOT_FLAG]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL]

//>> CLEAR_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL]
static inline bool GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_FULL]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY]

//>> CLEAR_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY]
static inline bool GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EMPTY]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_ENTRY_COUNT]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_VALID_FLAGS]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS]

//>> SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS]

//>> GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI,
                           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FSI_BYTE, TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS,
           TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SBE_FIFO_FSB_DOWNFIFO_STATUS_FIFO_EOT_FLAGS]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
