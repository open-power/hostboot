/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00024.H $         */
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

#ifndef __PROC_REG00024_H_
#define __PROC_REG00024_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG]

//>> PUT_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG]


//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB]

//>> CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB]
static inline bool GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB]

//>> CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB]
static inline bool GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB]

//>> CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB]
static inline bool GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB]

//>> CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB]
static inline bool GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB]

//>> CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB]
static inline bool GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB]

//>> CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB]
static inline bool GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB]

//>> CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB]
static inline bool GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB]

//>> CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB]
static inline bool GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES]

//>> CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES]
static inline bool GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES]

//>> CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES]
static inline bool GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES]

//>> CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES]
static inline bool GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES]

//>> CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES]
static inline bool GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES]

//>> CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES]
static inline bool GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES]

//>> CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES]
static inline bool GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES]

//>> CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES]
static inline bool GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES]

//>> CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES]
static inline bool GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_PIB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_PIB,
           TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_PIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_PIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_PIB(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_PIB,
           TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_PIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_PIB]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_PIB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_PIB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_PIB,
           TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_PIB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_PIB chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_PIB]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_FACES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_FACES,
           TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_FACES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_FACES]

//>> SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_FACES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_FACES(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_FACES,
           TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_FACES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_FACES]

//>> GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_FACES]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_FACES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_FACES,
           TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_FACES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_FACES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_RESET_INTR_FACES]

//>> PREP_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB]

//>> PUT_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB]


//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_ADDR,
           TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_ADDR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_ADDR,
           TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_ADDR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_ADDR,
           TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_ADDR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_R_NW]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_BUSY]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO,
           TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO,
           TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO,
           TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING]

//>> CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING]
static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_DATAOP_PENDING]

//>> PREP_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF]

//>> PUT_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF]


//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR]

//>> PREP_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG]

//>> PUT_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG]


//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]

//>> PREP_[TP_TPCHIP_TPC_CLOCK_STAT_SL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_CLOCK_STAT_SL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CLOCK_STAT_SL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_CLOCK_STAT_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_CLOCK_STAT_SL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CLOCK_STAT_SL;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_CLOCK_STAT_SL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL]

//>> PUT_[TP_TPCHIP_TPC_CLOCK_STAT_SL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_CLOCK_STAT_SL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_CLOCK_STAT_SL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_CLOCK_STAT_SL]


//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL]

//>> CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL]
static inline bool GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_PERV_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL]

//>> CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL]
static inline bool GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT1_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL]

//>> CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL]
static inline bool GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL]

//>> CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL]
static inline bool GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT3_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL]

//>> CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL]
static inline bool GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL]

//>> CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL]
static inline bool GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT5_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL]

//>> CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL]
static inline bool GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT6_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL]

//>> CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL]
static inline bool GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT7_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL]

//>> CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL]
static inline bool GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT8_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL]

//>> CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL]
static inline bool GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT9_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL]

//>> CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL]
static inline bool GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT10_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL]

//>> CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL]
static inline bool GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT11_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL]

//>> CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL]
static inline bool GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT12_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL]

//>> CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL]
static inline bool GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT13_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL]

//>> SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL]

//>> CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL]

//>> GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL]
static inline bool GET_TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CLOCK_STAT_SL));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT14_SL]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
