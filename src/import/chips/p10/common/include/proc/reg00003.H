/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00003.H $         */
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

#ifndef __PROC_REG00003_H_
#define __PROC_REG00003_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR]

//>> PUT_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR]


//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_PPE_XIXCR_XCR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_PPE_XIXCR_XCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_PPE_XIXCR_XCR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_PPE_XIXCR_XCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_PPE_XIXCR_XCR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_PPE_XIXCR_XCR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_PPE_XIXCR_XCR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_PPE_XIXCR_XCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_PPE_XIXCR_XCR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_PPE_XIXCR_XCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_PPE_XIXCR_XCR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_PPE_XIXCR_XCR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_PPE_XIXCR_XCR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_PPE_XIXCR_XCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_PPE_XIXCR_XCR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_PPE_XIXCR_XCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_PPE_XIXCR_XCR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_PPE_XIXCR_XCR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_NULL_CTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_NULL_CTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_NULL_CTR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_NULL_CTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_NULL_CTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_NULL_CTR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_NULL_CTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_NULL_CTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_NULL_CTR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_NULL_CTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_NULL_CTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_NULL_CTR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_NULL_CTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_NULL_CTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_NULL_CTR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_NULL_CTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_NULL_CTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR_NULL_CTR]

//>> PREP_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG]

//>> PUT_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG]


//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_FULL_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_OVER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_UNDER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_RESERVED_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_FULL_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_OVER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_UNDER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_RESERVED_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_OP_INDEX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_OP_INDEX(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_OP_INDEX,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_OP_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_OP_INDEX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_OP_INDEX]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_OP_INDEX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_OP_INDEX(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_OP_INDEX,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_OP_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_OP_INDEX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_OP_INDEX]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_OP_INDEX]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_OP_INDEX(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_OP_INDEX,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_OP_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_OP_INDEX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_OP_INDEX]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_32]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_COUNTER_REG_PARITY_ERRS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_33]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CLOCK_REG_PARITY_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_34]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_REG_PARITY_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_35]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_36]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_PARITY_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_37]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PATTERN_REG_PARITY_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_38]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_TDR_REG_PARITY_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_39]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_RDR_REG_PARITY_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_40]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_CONFIG_REG1_PARITY_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_41]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_42]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ERROR_REG_PARITY_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_43]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_CORRECTABLE_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_44]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_UNCORRECTABLE_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_45(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_45,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_45_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_45 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_45]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_45,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_45_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_45 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_45]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_45]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_45(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_45,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_45_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_45 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_45]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_STATUS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_STATUS,
           P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_STATUS]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_STATUS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_STATUS,
           P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_STATUS]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_STATUS]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_STATUS,
           P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ECC_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_47]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MM_ADDR_OVERLAP]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_48(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_48,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_48_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_48 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_48]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_48,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_48_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_48 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_48]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_48]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_48(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_48,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_48_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_48 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_48]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ACCESS_VIOLATION,
           P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ACCESS_VIOLATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ACCESS_VIOLATION]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ACCESS_VIOLATION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ACCESS_VIOLATION,
           P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ACCESS_VIOLATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ACCESS_VIOLATION]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ACCESS_VIOLATION,
           P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ACCESS_VIOLATION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ACCESS_VIOLATION]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_50]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_PORT_MULTIPLEXER_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_51]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ADDR_OUT_OF_RANGE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_52(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_52,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_52_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_52 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_52]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_52,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_52_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_52 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_52]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_52]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_52(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_52,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_52_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_52 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_STATUS_52]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_MEM_MAPPING_OVERLAP]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SEQUENCER_FSM_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SHIFTER_FSM_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_ANY_CONFIG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_PORT_MUX_INDICATOR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]

//>> PREP_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG]

//>> PUT_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG]


//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_FULL_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_OVER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_UNDER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_RESERVED_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_FULL_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_OVER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_UNDER_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_RESERVED_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_OP_INDEX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_OP_INDEX(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_OP_INDEX,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_OP_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_OP_INDEX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_OP_INDEX]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_OP_INDEX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_OP_INDEX(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_OP_INDEX,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_OP_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_OP_INDEX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_OP_INDEX]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_OP_INDEX]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_OP_INDEX(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_OP_INDEX,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_OP_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_OP_INDEX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_OP_INDEX]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_32]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_COUNTER_REG_PARITY_ERRS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_33]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CLOCK_REG_PARITY_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_34]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_REG_PARITY_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_35]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_PARITY_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_36]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_PARITY_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_37]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PATTERN_REG_PARITY_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_38]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_TDR_REG_PARITY_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_39]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_RDR_REG_PARITY_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_40]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_CONFIG_REG1_PARITY_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_41]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_42]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ERROR_REG_PARITY_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_43]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_CORRECTABLE_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_44]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_UNCORRECTABLE_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_45(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_45,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_45_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_45 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_45]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_45,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_45_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_45 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_45]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_45]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_45(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_45,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_45_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_45 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_45]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_STATUS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_STATUS,
           P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_STATUS]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_STATUS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_STATUS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_STATUS,
           P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_STATUS]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_STATUS]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_STATUS,
           P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ECC_STATUS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_47]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MM_ADDR_OVERLAP]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_48(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_48,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_48_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_48 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_48]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_48,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_48_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_48 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_48]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_48]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_48(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_48,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_48_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_48 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_48]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ACCESS_VIOLATION,
           P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ACCESS_VIOLATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ACCESS_VIOLATION]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ACCESS_VIOLATION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ACCESS_VIOLATION,
           P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ACCESS_VIOLATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ACCESS_VIOLATION]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ACCESS_VIOLATION]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ACCESS_VIOLATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ACCESS_VIOLATION,
           P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ACCESS_VIOLATION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ACCESS_VIOLATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ACCESS_VIOLATION]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_50]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_PORT_MULTIPLEXER_ERR]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_51]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ADDR_OUT_OF_RANGE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_52(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_52,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_52_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_52 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_52]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_52,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_52_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_52 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_52]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_52]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_52(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_52,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_52_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_52 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_STATUS_52]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_MEM_MAPPING_OVERLAP]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_SLAVE_SEL_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SEQUENCER_FSM_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SHIFTER_FSM_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_ANY_CONFIG_PARITY_ERR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_PORT_MUX_INDICATOR]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]

//>> SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.setBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]

//>> CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]

//>> GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]
static inline bool GET_P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG));
#endif
    return i_data.getBit<P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG_SPI_SEC_PIB_RETRY_RSP_INFO]

//>> PREP_[TP_TPCHIP_TPC_CPLT_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_CPLT_CTRL1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_CPLT_CTRL1_RW]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_CPLT_CTRL1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL1_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_RW]

//>> PUT_[TP_TPCHIP_TPC_CPLT_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_CPLT_CTRL1_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_CPLT_CTRL1_RW]

//>> PREP_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR]

//>> PUT_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR]

//>> PREP_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR]

//>> PUT_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR]


//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]

//>> SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]

//>> CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]

//>> GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]
static inline bool GET_TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_CPLT_CTRL1_RW, TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR, TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE]


//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO]


//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO]


//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_SIGNATURE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_SIGNATURE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_SIGNATURE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_SIGNATURE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_SIGNATURE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_SIGNATURE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_SIGNATURE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_SIGNATURE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_SIGNATURE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_SIGNATURE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_SIGNATURE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_SIGNATURE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_SIGNATURE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_SIGNATURE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_SIGNATURE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_SIGNATURE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_SIGNATURE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_SIGNATURE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_TRANS_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_TRANS_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_TRANS_DELAY,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_TRANS_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_TRANS_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_TRANS_DELAY]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_TRANS_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_TRANS_DELAY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_TRANS_DELAY,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_TRANS_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_TRANS_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_TRANS_DELAY]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_TRANS_DELAY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_TRANS_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_TRANS_DELAY,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_TRANS_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_TRANS_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_TRANS_DELAY]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW]


//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31]

//>> PREP_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI]

//>> GET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI]

//>> PUT_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI]

//>> PREP_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE]


//>> SET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0,
           TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0]

//>> SET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0,
           TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0]

//>> GET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0,
           TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_DMA_PIB_RCV_BUF0_REG_DATA0]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
