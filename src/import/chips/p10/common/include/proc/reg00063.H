/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00063.H $         */
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

#ifndef __PROC_REG00063_H_
#define __PROC_REG00063_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1]

//>> PUT_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1]


//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_PIB_MASTER_ID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_PIB_MASTER_ID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_PIB_MASTER_ID,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_PIB_MASTER_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_PIB_MASTER_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_PIB_MASTER_ID]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_PIB_MASTER_ID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_PIB_MASTER_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_PIB_MASTER_ID,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_PIB_MASTER_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_PIB_MASTER_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_PIB_MASTER_ID]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_PIB_MASTER_ID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_PIB_MASTER_ID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_PIB_MASTER_ID,
           TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_PIB_MASTER_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_PIB_MASTER_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1_PIB_MASTER_ID]

//>> PREP_[TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI]

//>> PUT_[TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI, TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI]

//>> PREP_[TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI, TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI_BYTE]


//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_CHIPID_CHIP_ID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_CHIPID_CHIP_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI, TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_CHIPID_CHIP_ID,
           TP_TPVSB_FSI_W_FSI2PIB_CHIPID_CHIP_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_CHIPID_CHIP_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_CHIPID_CHIP_ID]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_CHIPID_CHIP_ID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_CHIPID_CHIP_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI, TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_CHIPID_CHIP_ID,
           TP_TPVSB_FSI_W_FSI2PIB_CHIPID_CHIP_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_CHIPID_CHIP_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_CHIPID_CHIP_ID]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_CHIPID_CHIP_ID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_CHIPID_CHIP_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI, TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_CHIPID_CHIP_ID,
           TP_TPVSB_FSI_W_FSI2PIB_CHIPID_CHIP_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_CHIPID_CHIP_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_CHIPID_CHIP_ID]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW]


//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
