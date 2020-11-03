/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00049.H $         */
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

#ifndef __PROC_REG00049_H_
#define __PROC_REG00049_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG]

//>> PUT_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG]


//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_CLOCK_DIVIDER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_CLOCK_DIVIDER,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_CLOCK_DIVIDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_CLOCK_DIVIDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_CLOCK_DIVIDER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_CLOCK_DIVIDER,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_CLOCK_DIVIDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_CLOCK_DIVIDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_CLOCK_DIVIDER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_CLOCK_DIVIDER,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_CLOCK_DIVIDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_CLOCK_DIVIDER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_CLOCK_DIVIDER]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RECEIVE_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RECEIVE_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RECEIVE_DELAY,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RECEIVE_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RECEIVE_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RECEIVE_DELAY]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RECEIVE_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RECEIVE_DELAY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RECEIVE_DELAY,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RECEIVE_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RECEIVE_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RECEIVE_DELAY]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RECEIVE_DELAY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RECEIVE_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RECEIVE_DELAY,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RECEIVE_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RECEIVE_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RECEIVE_DELAY]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_RESERVED]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_ENABLE_RECEIVE_PACING]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPIMST_TRACE_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_TRACE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_TRACE_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_TRACE_SELECT,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_TRACE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_TRACE_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_TRACE_SELECT]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_TRACE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_TRACE_SELECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_TRACE_SELECT,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_TRACE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_TRACE_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_TRACE_SELECT]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_TRACE_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_TRACE_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_TRACE_SELECT,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_TRACE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_TRACE_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_TRACE_SELECT]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RESET_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RESET_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RESET_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RESET_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RESET_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RESET_CONTROL]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RESET_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RESET_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RESET_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RESET_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RESET_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RESET_CONTROL]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RESET_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RESET_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RESET_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RESET_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RESET_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_RESET_CONTROL]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_SPIMM_ADDR_CORR_DIS]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_CONTROL]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_CONTROL]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_CONTROL,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_ECC_CONTROL]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SCK_MMSPISM_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_SLAVE_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_SLAVE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_SLAVE_RESET,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_SLAVE_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_SLAVE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_SLAVE_RESET]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_SLAVE_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_SLAVE_RESET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_SLAVE_RESET,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_SLAVE_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_SLAVE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_SLAVE_RESET]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_SLAVE_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_SLAVE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_SLAVE_RESET,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_SLAVE_RESET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_SLAVE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_SPI_SLAVE_RESET]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_LOOPBACK_ENABLE]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED,
           TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG_CLOCK_CONFIG_RESERVED]

//>> PREP_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1]

//>> PUT_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1]


//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK]

//>> CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK]
static inline bool GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_SPI_RESOURCE_LOCK]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_PIB_MASTER_ID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_PIB_MASTER_ID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_PIB_MASTER_ID,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_PIB_MASTER_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_PIB_MASTER_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_PIB_MASTER_ID]

//>> SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_PIB_MASTER_ID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_PIB_MASTER_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_PIB_MASTER_ID,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_PIB_MASTER_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_PIB_MASTER_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_PIB_MASTER_ID]

//>> GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_PIB_MASTER_ID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_PIB_MASTER_ID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_PIB_MASTER_ID,
           TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_PIB_MASTER_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_PIB_MASTER_ID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1_PIB_MASTER_ID]

//>> PREP_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT]

//>> PUT_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT]


//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQOUT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT,
           TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_HIRES_FREQOUT]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_UPDATE_COMPLETE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_FREQ_CHANGE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_BLOCK_ACTIVE]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]

//>> SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]

//>> CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]

//>> GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]
static inline bool GET_TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_STAT_LOCK]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW]


//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_17_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_20_SPARE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_24_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_25_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_30_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_RW));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_31_FREE_USAGE]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
