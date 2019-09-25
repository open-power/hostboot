/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00061.H $         */
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

#ifndef __PROC_REG00061_H_
#define __PROC_REG00061_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_STATUS_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_STATUS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_STATUS_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_STATUS_REG;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_STATUS_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_STATUS_REG));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT_
(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT_;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT_
(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT_;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT_, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT_
(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT_));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT_, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT__ERROR_REG_Q(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT_));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT__ERROR_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT__ERROR_REG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT__ERROR_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT__ERROR_REG_Q(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT_));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT__ERROR_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT__ERROR_REG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT__ERROR_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT__ERROR_REG_Q(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT_));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT__ERROR_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT__ERROR_REG_Q_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_ERROR_INJECT__ERROR_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_STATUS_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_STATUS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_STATUS_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_STATUS_REG;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_STATUS_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_STATUS_REG));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_EG_SCF_PBCFG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_PBCFG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_EG_SCF_PBCFG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_EG_SCF_PBCFG1;
#endif
    return fapi2::getScom(i_target, VAS_VA_EG_SCF_PBCFG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_EG_SCF_PBCFG1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return fapi2::putScom(i_target, VAS_VA_EG_SCF_PBCFG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_G_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_WR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_LN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_G_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_VG_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DISABLE_NN_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_RD_GO_M_QOS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_RESERVED_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_RESERVED_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_RESERVED_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_RESERVED_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_RESERVED_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_PBCFG1_RESERVED_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_PBCFG1_RESERVED_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_PBCFG1_RESERVED_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_PBCFG1_RESERVED_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_PBCFG1_RESERVED_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_PBCFG1_RESERVED_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_PBCFG1_RESERVED_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_SKIP_G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_SKIP_G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_SKIP_G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_SKIP_G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_SKIP_G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_SKIP_G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_SKIP_G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_PBCFG1_SKIP_G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_SKIP_G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_PBCFG1_SKIP_G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_PBCFG1_SKIP_G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_SKIP_G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_PBCFG1_SKIP_G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_PBCFG1_SKIP_G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_SKIP_G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_PBCFG1_SKIP_G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_PBCFG1_SKIP_G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_SKIP_G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_HANG_SM_ON_ARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_RESERVED_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_RESERVED_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_RESERVED_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_RESERVED_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_RESERVED_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_RESERVED_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_RESERVED_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_PBCFG1_RESERVED_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_RESERVED_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_PBCFG1_RESERVED_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_PBCFG1_RESERVED_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_RESERVED_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_PBCFG1_RESERVED_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_PBCFG1_RESERVED_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_RESERVED_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_PBCFG1_RESERVED_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_PBCFG1_RESERVED_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_RESERVED_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_CFG_PUMP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DMA_WR_NOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.setBit<VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.clearBit<VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.getBit<VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DMA_PART_WR_NOT_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DMA_RD_VG_RST_TMASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DMA_RD_VG_RST_TMASK,
           VAS_VA_EG_SCF_PBCFG1_DMA_RD_VG_RST_TMASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DMA_RD_VG_RST_TMASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DMA_RD_VG_RST_TMASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DMA_RD_VG_RST_TMASK,
           VAS_VA_EG_SCF_PBCFG1_DMA_RD_VG_RST_TMASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DMA_RD_VG_RST_TMASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_PBCFG1_DMA_RD_VG_RST_TMASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_PBCFG1_DMA_RD_VG_RST_TMASK,
           VAS_VA_EG_SCF_PBCFG1_DMA_RD_VG_RST_TMASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DMA_RD_VG_RST_TMASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DMA_WR_VG_RST_TMASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DMA_WR_VG_RST_TMASK,
           VAS_VA_EG_SCF_PBCFG1_DMA_WR_VG_RST_TMASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DMA_WR_VG_RST_TMASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_EG_SCF_PBCFG1_DMA_WR_VG_RST_TMASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return o_data.insertFromRight<VAS_VA_EG_SCF_PBCFG1_DMA_WR_VG_RST_TMASK,
           VAS_VA_EG_SCF_PBCFG1_DMA_WR_VG_RST_TMASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DMA_WR_VG_RST_TMASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_EG_SCF_PBCFG1_DMA_WR_VG_RST_TMASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_EG_SCF_PBCFG1));
#endif
    return i_data.extractToRight<VAS_VA_EG_SCF_PBCFG1_DMA_WR_VG_RST_TMASK,
           VAS_VA_EG_SCF_PBCFG1_DMA_WR_VG_RST_TMASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_EG_SCF_PBCFG1_DMA_WR_VG_RST_TMASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_FIR_MASK_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_FIR_MASK_REG_RW;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_FIR_MASK_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_FIR_MASK_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_LOGIC_HW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_RD_ADDR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_WR_ADDR_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_CE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_OB_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_PB_MASTER_FSM_HANG_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_UE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_SW_CAST_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_SMF_ACCESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_EG_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_IN_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WC_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_RG_ECC_SUE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_RD_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_RD_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_HYP_WR_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_OS_WR_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_HYP_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_MMIO_NON8B_OS_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WM_WIN_NOT_OPEN_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WM_MULTIHIT_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_DISABLED_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_PG_MIG_SIZE_MISMATCH_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_NOTIFY_FAILED_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_WR_MON_NOT_DISABLED_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_VAS_REJECTED_PASTE_CMD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_DATA_HANG_DETECTED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_INCOMING_PB_PARITY_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_SCOM1_SAT_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_NX_LOCAL_XSTOP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_SCOM_MMIO_ADDR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_FIR_MASK_REG_RW, VAS_VA_RG_SCF_FIR_MASK_REG_WO_AND,
                           VAS_VA_RG_SCF_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_FIR_MASK_REG_CQ_RG_FIR_TOPO_INDEX_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_INERRRPT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_INERRRPT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_INERRRPT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_INERRRPT;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_INERRRPT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_INERRRPT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_INERRRPT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_INERRRPT_BIT31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_INERRRPT_BIT31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_INERRRPT_BIT31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_INERRRPT_BIT31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_INERRRPT_BIT31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_INERRRPT_BIT31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_INERRRPT_BIT31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_VAS_VA_RG_SCF_INERRRPT_BIT31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_INERRRPT));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_INERRRPT_BIT31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access VAS_VA_RG_SCF_INERRRPT_BIT31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_RESERVE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_RESERVE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_RESERVE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_RESERVE;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_RESERVE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_RESERVE(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_RESERVE));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_RESERVE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WRMON1BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON1BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WRMON1BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON1BAR;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WRMON1BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WRMON1BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WRMON1BAR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WRMON1BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WRMON4WID(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON4WID;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WRMON4WID(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON4WID;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WRMON4WID, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WRMON4WID(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WRMON4WID));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WRMON4WID, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WRMON5CMP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON5CMP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WRMON5CMP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON5CMP;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WRMON5CMP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WRMON5CMP(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WRMON5CMP));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WRMON5CMP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}



#ifndef __PPE_HCODE__
}
}

#endif
#endif
