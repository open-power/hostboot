/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00028.H $         */
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

#ifndef __PROC_REG00028_H_
#define __PROC_REG00028_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG]

//>> PUT_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG]


//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HC,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HC,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HC,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIB]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIB]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SIB]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SMS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SMS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SMS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SMS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SMS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SMS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SMS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_SMS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MCS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MCS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MCS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MCS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MCS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MCS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MCS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_XSR_MCS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SPRG0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SPRG0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SPRG0,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SPRG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SPRG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SPRG0]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SPRG0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SPRG0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SPRG0,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SPRG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SPRG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SPRG0]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SPRG0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SPRG0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SPRG0,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SPRG0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SPRG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMDBG_SPRG0]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HC,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HC,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HC,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIB]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIB]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SIB]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SMS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SMS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SMS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SMS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SMS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SMS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SMS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_SMS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MCS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MCS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MCS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MCS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MCS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MCS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MCS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_XSR_MCS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_CCSR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_CCSR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_CCSR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_CCSR_RW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_CCSR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_CCSR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_CCSR_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_CCSR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_CCSR_RW]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_CCSR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_CCSR_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_CCSR_RW, TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_CCSR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_CCSR_RW]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_CCSR_RW, TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_CCSR_RW, TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_CCSR_RW, TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG,
           TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_CCSR_RW, TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG,
           TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_CCSR_RW, TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG,
           TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_CCSR_OCB_OCI_CCSR_CORE_CONFIG]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CMD1A_RESERVED_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1A_CLEAR_STICKY_BITS_1A]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SWD1A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SWD1A;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SWD1A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SWD1A;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SWD1A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1A]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SWD1A(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD1A));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SWD1A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1A]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A,
           TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A,
           TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD1A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A,
           TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1A_OCB_OCI_O2SWD1A_O2S_WDATA_1A]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_SPARE_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_BAR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0_LINEAR_WINDOW_MASK]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_LINEAR_WINDOW_SCRESP]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0_SPARE0]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI_REGION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI_REGION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI_REGION]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI_REGION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI_REGION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI_REGION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_OCI_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_START]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_START]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_START]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3_START]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_INTR_ACTION_0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_LENGTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_WRITE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_READ_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2_PULL_ENABLE]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2,
           TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2,
           TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS2_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS2_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2,
           TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS2_OCB_OCI_OCCS2_OCC_SCRATCH_2]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0RR_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
