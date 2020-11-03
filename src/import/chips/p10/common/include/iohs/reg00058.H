/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00058.H $         */
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

#ifndef __IOHS_REG00058_H_
#define __IOHS_REG00058_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[DLP_LINK1_QUALITY]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_LINK1_QUALITY(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK1_QUALITY;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_LINK1_QUALITY]

//>> GET_[DLP_LINK1_QUALITY]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_LINK1_QUALITY(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK1_QUALITY;
#endif
    return fapi2::getScom(i_target, DLP_LINK1_QUALITY, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_LINK1_QUALITY]

//>> PUT_[DLP_LINK1_QUALITY]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_LINK1_QUALITY(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_QUALITY));
#endif
    return fapi2::putScom(i_target, DLP_LINK1_QUALITY, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_LINK1_QUALITY]


//>> SET_[DLP_LINK1_QUALITY_TX_BW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_QUALITY_TX_BW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK1_QUALITY_TX_BW,
           DLP_LINK1_QUALITY_TX_BW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_QUALITY_TX_BW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_QUALITY_TX_BW]

//>> SET_[DLP_LINK1_QUALITY_TX_BW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_QUALITY_TX_BW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK1_QUALITY_TX_BW,
           DLP_LINK1_QUALITY_TX_BW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_QUALITY_TX_BW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_QUALITY_TX_BW]

//>> GET_[DLP_LINK1_QUALITY_TX_BW]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_QUALITY_TX_BW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_QUALITY));
#endif
    return i_data.extractToRight<DLP_LINK1_QUALITY_TX_BW,
           DLP_LINK1_QUALITY_TX_BW_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_QUALITY_TX_BW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_QUALITY_TX_BW]

//>> SET_[DLP_LINK1_QUALITY_RX_BW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_QUALITY_RX_BW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK1_QUALITY_RX_BW,
           DLP_LINK1_QUALITY_RX_BW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_QUALITY_RX_BW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_QUALITY_RX_BW]

//>> SET_[DLP_LINK1_QUALITY_RX_BW]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_QUALITY_RX_BW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK1_QUALITY_RX_BW,
           DLP_LINK1_QUALITY_RX_BW_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_QUALITY_RX_BW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_QUALITY_RX_BW]

//>> GET_[DLP_LINK1_QUALITY_RX_BW]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_QUALITY_RX_BW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_QUALITY));
#endif
    return i_data.extractToRight<DLP_LINK1_QUALITY_RX_BW,
           DLP_LINK1_QUALITY_RX_BW_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_QUALITY_RX_BW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_QUALITY_RX_BW]

//>> SET_[DLP_LINK1_QUALITY_ERROR_RATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_QUALITY_ERROR_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK1_QUALITY_ERROR_RATE,
           DLP_LINK1_QUALITY_ERROR_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_QUALITY_ERROR_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_QUALITY_ERROR_RATE]

//>> SET_[DLP_LINK1_QUALITY_ERROR_RATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_QUALITY_ERROR_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK1_QUALITY_ERROR_RATE,
           DLP_LINK1_QUALITY_ERROR_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_QUALITY_ERROR_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_QUALITY_ERROR_RATE]

//>> GET_[DLP_LINK1_QUALITY_ERROR_RATE]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_QUALITY_ERROR_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_QUALITY));
#endif
    return i_data.extractToRight<DLP_LINK1_QUALITY_ERROR_RATE,
           DLP_LINK1_QUALITY_ERROR_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_QUALITY_ERROR_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_QUALITY_ERROR_RATE]

//>> SET_[DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3,
           DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3]

//>> SET_[DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3,
           DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3]

//>> GET_[DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_QUALITY));
#endif
    return i_data.extractToRight<DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3,
           DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3]

//>> SET_[DLP_LINK1_QUALITY_SPARE_COUNTER_2]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_QUALITY_SPARE_COUNTER_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK1_QUALITY_SPARE_COUNTER_2,
           DLP_LINK1_QUALITY_SPARE_COUNTER_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_QUALITY_SPARE_COUNTER_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_QUALITY_SPARE_COUNTER_2]

//>> SET_[DLP_LINK1_QUALITY_SPARE_COUNTER_2]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_QUALITY_SPARE_COUNTER_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_QUALITY));
#endif
    return o_data.insertFromRight<DLP_LINK1_QUALITY_SPARE_COUNTER_2,
           DLP_LINK1_QUALITY_SPARE_COUNTER_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_QUALITY_SPARE_COUNTER_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_QUALITY_SPARE_COUNTER_2]

//>> GET_[DLP_LINK1_QUALITY_SPARE_COUNTER_2]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_QUALITY_SPARE_COUNTER_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_QUALITY));
#endif
    return i_data.extractToRight<DLP_LINK1_QUALITY_SPARE_COUNTER_2,
           DLP_LINK1_QUALITY_SPARE_COUNTER_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_QUALITY_SPARE_COUNTER_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_QUALITY_SPARE_COUNTER_2]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
