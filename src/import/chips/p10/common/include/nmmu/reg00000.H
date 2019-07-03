/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/nmmu/reg00000.H $         */
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

#ifndef __NMMU_REG00000_H_
#define __NMMU_REG00000_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace nmmu
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG;
#endif
    return fapi2::getScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return fapi2::putScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_LN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_LN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_VG_NOT_SYS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_DISABLE_NN_RN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_PAU_PEC_CONFIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NX_FREEZE_MODES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_BAR_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_SKIP_G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_ARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_NXCQ_HANG_SM_ON_LINK_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_CFG_PUMP_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_RD_VG_RESET_TIMER_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_DMA_WR_VG_RESET_TIMER_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK,
           FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_MMCQ_PB_MODE_REG_ADDR_EXT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG;
#endif
    return fapi2::getScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG));
#endif
    return fapi2::putScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_POLL_SCALE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_POLL_SCALE,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_POLL_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_POLL_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_POLL_SCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_POLL_SCALE,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_POLL_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_POLL_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_POLL_SCALE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_POLL_SCALE,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_POLL_SCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_POLL_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_DATA_SCALE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_DATA_SCALE,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_DATA_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_DATA_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_DATA_SCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_DATA_SCALE,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_DATA_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_DATA_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_DATA_SCALE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_DATA_SCALE,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_DATA_SCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_DATA_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_SHM_SCALE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_SHM_SCALE,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_SHM_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_SHM_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_SHM_SCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_SHM_SCALE,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_SHM_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_SHM_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_SHM_SCALE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_SHM_SCALE,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_SHM_SCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_MISC_CONTROL_REG_SHM_SCALE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG;
#endif
    return fapi2::getScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG));
#endif
    return fapi2::putScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_ECC_INJECT_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_INJECT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY,
           FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_PB_ECC_REG_PBCQ_ARRAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NMMU_PMU1_CNT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NMMU_PMU1_CNT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NMMU_PMU1_CNT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NMMU_PMU1_CNT_REG;
#endif
    return fapi2::getScom(i_target, NMMU_PMU1_CNT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NMMU_PMU1_CNT_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NMMU_PMU1_CNT_REG));
#endif
    return fapi2::putScom(i_target, NMMU_PMU1_CNT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NMMU_PMU1_CNT_REG_MM_PMU1_CNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_PMU1_CNT_REG));
#endif
    return o_data.insertFromRight<NMMU_PMU1_CNT_REG_MM_PMU1_CNT,
           NMMU_PMU1_CNT_REG_MM_PMU1_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_PMU1_CNT_REG_MM_PMU1_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NMMU_PMU1_CNT_REG_MM_PMU1_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_PMU1_CNT_REG));
#endif
    return o_data.insertFromRight<NMMU_PMU1_CNT_REG_MM_PMU1_CNT,
           NMMU_PMU1_CNT_REG_MM_PMU1_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_PMU1_CNT_REG_MM_PMU1_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NMMU_PMU1_CNT_REG_MM_PMU1_CNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_PMU1_CNT_REG));
#endif
    return i_data.extractToRight<NMMU_PMU1_CNT_REG_MM_PMU1_CNT,
           NMMU_PMU1_CNT_REG_MM_PMU1_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NMMU_PMU1_CNT_REG_MM_PMU1_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
