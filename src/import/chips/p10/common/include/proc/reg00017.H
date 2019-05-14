/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00017.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef __PROC_REG00017_H_
#define __PROC_REG00017_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_STATUS_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_STATUS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_STATUS_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_STATUS_REG;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_STATUS_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_STATUS_REG));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_BUFCTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_BUFCTL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_BUFCTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_BUFCTL;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_BUFCTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_BUFCTL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_BUFCTL));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_BUFCTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_BUFCTL_TOTAL_FREE_BUF_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_BUFCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_BUFCTL_TOTAL_FREE_BUF_COUNT,
           VAS_VA_RG_SCF_BUFCTL_TOTAL_FREE_BUF_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_BUFCTL_TOTAL_FREE_BUF_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_BUFCTL_TOTAL_FREE_BUF_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_BUFCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_BUFCTL_TOTAL_FREE_BUF_COUNT,
           VAS_VA_RG_SCF_BUFCTL_TOTAL_FREE_BUF_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_BUFCTL_TOTAL_FREE_BUF_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_BUFCTL_TOTAL_FREE_BUF_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_BUFCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_BUFCTL_TOTAL_FREE_BUF_COUNT,
           VAS_VA_RG_SCF_BUFCTL_TOTAL_FREE_BUF_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_BUFCTL_TOTAL_FREE_BUF_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_BUFCTL_CONSUMED_BUF_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_BUFCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_BUFCTL_CONSUMED_BUF_COUNT,
           VAS_VA_RG_SCF_BUFCTL_CONSUMED_BUF_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_BUFCTL_CONSUMED_BUF_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_BUFCTL_CONSUMED_BUF_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_BUFCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_BUFCTL_CONSUMED_BUF_COUNT,
           VAS_VA_RG_SCF_BUFCTL_CONSUMED_BUF_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_BUFCTL_CONSUMED_BUF_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_BUFCTL_CONSUMED_BUF_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_BUFCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_BUFCTL_CONSUMED_BUF_COUNT,
           VAS_VA_RG_SCF_BUFCTL_CONSUMED_BUF_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_BUFCTL_CONSUMED_BUF_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
