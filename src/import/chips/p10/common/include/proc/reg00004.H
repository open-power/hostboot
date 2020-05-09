/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00004.H $         */
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

#ifndef __PROC_REG00004_H_
#define __PROC_REG00004_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_B_SCISM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SCISM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SCISM;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_B_SCISM]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SCISM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SCISM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SCISM;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SCISM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SCISM]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_B_SCISM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SCISM(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SCISM));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SCISM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_B_SCISM]


//>> PREP_[TP_TPVSB_FSI_W_SLAVE_B_SISS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SISS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SISS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SLAVE_B_SISS]

//>> GET_[TP_TPVSB_FSI_W_SLAVE_B_SISS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SISS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SISS;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SISS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SLAVE_B_SISS]

//>> PUT_[TP_TPVSB_FSI_W_SLAVE_B_SISS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SISS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SISS));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SISS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SLAVE_B_SISS]


//>> PREP_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI]

//>> PUT_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI, TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI]

//>> PREP_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI, TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI_BYTE]


//>> SET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_INTERRUPT_STATUS_REG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_INTERRUPT_STATUS_REG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI, TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_INTERRUPT_STATUS_REG,
           TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_INTERRUPT_STATUS_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_INTERRUPT_STATUS_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_INTERRUPT_STATUS_REG]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_INTERRUPT_STATUS_REG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_INTERRUPT_STATUS_REG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI, TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_INTERRUPT_STATUS_REG,
           TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_INTERRUPT_STATUS_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_INTERRUPT_STATUS_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_INTERRUPT_STATUS_REG]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_INTERRUPT_STATUS_REG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_INTERRUPT_STATUS_REG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI, TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_INTERRUPT_STATUS_REG,
           TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_INTERRUPT_STATUS_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_INTERRUPT_STATUS_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_FSI2SPI_INTERRUPT_INTERRUPT_STATUS_REG]

//>> PREP_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG]

//>> PUT_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG]


//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST0_TRANSMIT_DATA_REG_TRANSMIT_DATA_REG_Q]

//>> PREP_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1]

//>> PUT_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1]


//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]

//>> CLEAR_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]
static inline bool GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_SPI_RESOURCE_LOCK]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_PIB_MASTER_ID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_PIB_MASTER_ID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_PIB_MASTER_ID,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_PIB_MASTER_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_PIB_MASTER_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_PIB_MASTER_ID]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_PIB_MASTER_ID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_PIB_MASTER_ID(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_PIB_MASTER_ID,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_PIB_MASTER_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_PIB_MASTER_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_PIB_MASTER_ID]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_PIB_MASTER_ID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_PIB_MASTER_ID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_PIB_MASTER_ID,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_PIB_MASTER_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_PIB_MASTER_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_CONFIG1_PIB_MASTER_ID]

//>> PREP_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG]

//>> PUT_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG]


//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST1_RECEIVE_DATA_REG_RECEIVE_DATA_REG_Q]

//>> PREP_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG]

//>> PUT_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG]


//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RECEIVE_DELAY]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]

//>> CLEAR_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]
static inline bool GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_RESERVED]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> CLEAR_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline bool GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_TRACE_SELECT]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_RESET_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> CLEAR_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline bool GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_ECC_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> CLEAR_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline bool GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_SPI_SLAVE_RESET]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> CLEAR_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline bool GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]

//>> SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]

//>> GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]

//>> PREP_[VAS_VA_RG_SCF_CAMDATA0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_CAMDATA0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_CAMDATA0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_RG_SCF_CAMDATA0]

//>> GET_[VAS_VA_RG_SCF_CAMDATA0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_CAMDATA0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_CAMDATA0;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_CAMDATA0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_RG_SCF_CAMDATA0]

//>> PUT_[VAS_VA_RG_SCF_CAMDATA0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_CAMDATA0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_CAMDATA0));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_CAMDATA0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_RG_SCF_CAMDATA0]


//>> SET_[VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_CAMDATA0));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0,
           VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0]

//>> SET_[VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_CAMDATA0));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0,
           VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0]

//>> GET_[VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_CAMDATA0));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0,
           VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_CAMDATA0_CAM_DISPLAY_REG_0]

//>> PREP_[VAS_VA_RG_SCF_CAMDISPCNTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_CAMDISPCNTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_CAMDISPCNTL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_RG_SCF_CAMDISPCNTL]

//>> GET_[VAS_VA_RG_SCF_CAMDISPCNTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_CAMDISPCNTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_CAMDISPCNTL;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_CAMDISPCNTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_RG_SCF_CAMDISPCNTL]

//>> PUT_[VAS_VA_RG_SCF_CAMDISPCNTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_CAMDISPCNTL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_CAMDISPCNTL));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_CAMDISPCNTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_RG_SCF_CAMDISPCNTL]


//>> PREP_[VAS_VA_RG_SCF_MMIOCTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_MMIOCTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_MMIOCTL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_RG_SCF_MMIOCTL]

//>> GET_[VAS_VA_RG_SCF_MMIOCTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_MMIOCTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_MMIOCTL;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_MMIOCTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MMIOCTL]

//>> PUT_[VAS_VA_RG_SCF_MMIOCTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_MMIOCTL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_MMIOCTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_RG_SCF_MMIOCTL]


//>> SET_[VAS_VA_RG_SCF_MMIOCTL_INIT]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_INIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MMIOCTL_INIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_INIT]

//>> SET_[VAS_VA_RG_SCF_MMIOCTL_INIT]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_INIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MMIOCTL_INIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_INIT]

//>> SET_[VAS_VA_RG_SCF_MMIOCTL_INIT]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_INIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MMIOCTL_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_INIT]

//>> CLEAR_[VAS_VA_RG_SCF_MMIOCTL_INIT]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MMIOCTL_INIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MMIOCTL_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MMIOCTL_INIT]

//>> GET_[VAS_VA_RG_SCF_MMIOCTL_INIT]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MMIOCTL_INIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MMIOCTL_INIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MMIOCTL_INIT]

//>> GET_[VAS_VA_RG_SCF_MMIOCTL_INIT]
static inline bool GET_VAS_VA_RG_SCF_MMIOCTL_INIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MMIOCTL_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MMIOCTL_INIT]

//>> SET_[VAS_VA_RG_SCF_MMIOCTL_COMP]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_COMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MMIOCTL_COMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_COMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_COMP]

//>> SET_[VAS_VA_RG_SCF_MMIOCTL_COMP]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_COMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MMIOCTL_COMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_COMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_COMP]

//>> SET_[VAS_VA_RG_SCF_MMIOCTL_COMP]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_COMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MMIOCTL_COMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_COMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_COMP]

//>> CLEAR_[VAS_VA_RG_SCF_MMIOCTL_COMP]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MMIOCTL_COMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MMIOCTL_COMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_COMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MMIOCTL_COMP]

//>> GET_[VAS_VA_RG_SCF_MMIOCTL_COMP]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MMIOCTL_COMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MMIOCTL_COMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_COMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MMIOCTL_COMP]

//>> GET_[VAS_VA_RG_SCF_MMIOCTL_COMP]
static inline bool GET_VAS_VA_RG_SCF_MMIOCTL_COMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MMIOCTL_COMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_COMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MMIOCTL_COMP]

//>> SET_[VAS_VA_RG_SCF_MMIOCTL_OPTYPE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_OPTYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MMIOCTL_OPTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_OPTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_OPTYPE]

//>> SET_[VAS_VA_RG_SCF_MMIOCTL_OPTYPE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_OPTYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MMIOCTL_OPTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_OPTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_OPTYPE]

//>> SET_[VAS_VA_RG_SCF_MMIOCTL_OPTYPE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_OPTYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MMIOCTL_OPTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_OPTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_OPTYPE]

//>> CLEAR_[VAS_VA_RG_SCF_MMIOCTL_OPTYPE]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MMIOCTL_OPTYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MMIOCTL_OPTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_OPTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MMIOCTL_OPTYPE]

//>> GET_[VAS_VA_RG_SCF_MMIOCTL_OPTYPE]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MMIOCTL_OPTYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MMIOCTL_OPTYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_OPTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MMIOCTL_OPTYPE]

//>> GET_[VAS_VA_RG_SCF_MMIOCTL_OPTYPE]
static inline bool GET_VAS_VA_RG_SCF_MMIOCTL_OPTYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MMIOCTL_OPTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_OPTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MMIOCTL_OPTYPE]

//>> SET_[VAS_VA_RG_SCF_MMIOCTL_ACTYPE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_ACTYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MMIOCTL_ACTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_ACTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_ACTYPE]

//>> SET_[VAS_VA_RG_SCF_MMIOCTL_ACTYPE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_ACTYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MMIOCTL_ACTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_ACTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_ACTYPE]

//>> SET_[VAS_VA_RG_SCF_MMIOCTL_ACTYPE]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_ACTYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MMIOCTL_ACTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_ACTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_ACTYPE]

//>> CLEAR_[VAS_VA_RG_SCF_MMIOCTL_ACTYPE]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MMIOCTL_ACTYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MMIOCTL_ACTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_ACTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MMIOCTL_ACTYPE]

//>> GET_[VAS_VA_RG_SCF_MMIOCTL_ACTYPE]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MMIOCTL_ACTYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MMIOCTL_ACTYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_ACTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MMIOCTL_ACTYPE]

//>> GET_[VAS_VA_RG_SCF_MMIOCTL_ACTYPE]
static inline bool GET_VAS_VA_RG_SCF_MMIOCTL_ACTYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MMIOCTL_ACTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_ACTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MMIOCTL_ACTYPE]

//>> SET_[VAS_VA_RG_SCF_MMIOCTL_OP_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_OP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MMIOCTL_OP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_OP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_OP_ERR]

//>> SET_[VAS_VA_RG_SCF_MMIOCTL_OP_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_OP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MMIOCTL_OP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_OP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_OP_ERR]

//>> SET_[VAS_VA_RG_SCF_MMIOCTL_OP_ERR]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_OP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.setBit<VAS_VA_RG_SCF_MMIOCTL_OP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_OP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_OP_ERR]

//>> CLEAR_[VAS_VA_RG_SCF_MMIOCTL_OP_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_VAS_VA_RG_SCF_MMIOCTL_OP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.clearBit<VAS_VA_RG_SCF_MMIOCTL_OP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_OP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[VAS_VA_RG_SCF_MMIOCTL_OP_ERR]

//>> GET_[VAS_VA_RG_SCF_MMIOCTL_OP_ERR]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MMIOCTL_OP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MMIOCTL_OP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_OP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MMIOCTL_OP_ERR]

//>> GET_[VAS_VA_RG_SCF_MMIOCTL_OP_ERR]
static inline bool GET_VAS_VA_RG_SCF_MMIOCTL_OP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return i_data.getBit<VAS_VA_RG_SCF_MMIOCTL_OP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_OP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MMIOCTL_OP_ERR]

//>> SET_[VAS_VA_RG_SCF_MMIOCTL_OFFSET]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_OFFSET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MMIOCTL_OFFSET,
           VAS_VA_RG_SCF_MMIOCTL_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_OFFSET]

//>> SET_[VAS_VA_RG_SCF_MMIOCTL_OFFSET]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MMIOCTL_OFFSET,
           VAS_VA_RG_SCF_MMIOCTL_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_OFFSET]

//>> GET_[VAS_VA_RG_SCF_MMIOCTL_OFFSET]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MMIOCTL_OFFSET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MMIOCTL_OFFSET,
           VAS_VA_RG_SCF_MMIOCTL_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MMIOCTL_OFFSET]

//>> SET_[VAS_VA_RG_SCF_MMIOCTL_WINID]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_WINID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MMIOCTL_WINID,
           VAS_VA_RG_SCF_MMIOCTL_WINID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_WINID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_WINID]

//>> SET_[VAS_VA_RG_SCF_MMIOCTL_WINID]
static inline fapi2::buffer<uint64_t>& SET_VAS_VA_RG_SCF_MMIOCTL_WINID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return o_data.insertFromRight<VAS_VA_RG_SCF_MMIOCTL_WINID,
           VAS_VA_RG_SCF_MMIOCTL_WINID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_WINID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[VAS_VA_RG_SCF_MMIOCTL_WINID]

//>> GET_[VAS_VA_RG_SCF_MMIOCTL_WINID]
static inline fapi2::buffer<uint64_t>& GET_VAS_VA_RG_SCF_MMIOCTL_WINID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_MMIOCTL));
#endif
    return i_data.extractToRight<VAS_VA_RG_SCF_MMIOCTL_WINID,
           VAS_VA_RG_SCF_MMIOCTL_WINID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access VAS_VA_RG_SCF_MMIOCTL_WINID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[VAS_VA_RG_SCF_MMIOCTL_WINID]

//>> PREP_[VAS_VA_RG_SCF_WRMON2WID]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WRMON2WID(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON2WID;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_RG_SCF_WRMON2WID]

//>> GET_[VAS_VA_RG_SCF_WRMON2WID]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WRMON2WID(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON2WID;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WRMON2WID, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_RG_SCF_WRMON2WID]

//>> PUT_[VAS_VA_RG_SCF_WRMON2WID]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WRMON2WID(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WRMON2WID));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WRMON2WID, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_RG_SCF_WRMON2WID]


//>> PREP_[VAS_VA_RG_SCF_WRMON3CMP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WRMON3CMP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON3CMP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_RG_SCF_WRMON3CMP]

//>> GET_[VAS_VA_RG_SCF_WRMON3CMP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WRMON3CMP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON3CMP;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WRMON3CMP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_RG_SCF_WRMON3CMP]

//>> PUT_[VAS_VA_RG_SCF_WRMON3CMP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WRMON3CMP(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WRMON3CMP));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WRMON3CMP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_RG_SCF_WRMON3CMP]


//>> PREP_[VAS_VA_RG_SCF_WRMON7BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VAS_VA_RG_SCF_WRMON7BAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON7BAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[VAS_VA_RG_SCF_WRMON7BAR]

//>> GET_[VAS_VA_RG_SCF_WRMON7BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VAS_VA_RG_SCF_WRMON7BAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VAS_VA_RG_SCF_WRMON7BAR;
#endif
    return fapi2::getScom(i_target, VAS_VA_RG_SCF_WRMON7BAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[VAS_VA_RG_SCF_WRMON7BAR]

//>> PUT_[VAS_VA_RG_SCF_WRMON7BAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VAS_VA_RG_SCF_WRMON7BAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VAS_VA_RG_SCF_WRMON7BAR));
#endif
    return fapi2::putScom(i_target, VAS_VA_RG_SCF_WRMON7BAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[VAS_VA_RG_SCF_WRMON7BAR]



//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
