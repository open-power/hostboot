/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00013.H $         */
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

#ifndef __OMIC_REG00013_H_
#define __OMIC_REG00013_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CMN_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CMN_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CMN_CONFIG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CMN_CONFIG;
#endif
    return fapi2::getScom(i_target, CMN_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CMN_CONFIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return fapi2::putScom(i_target, CMN_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_SPARE,
           CMN_CONFIG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_SPARE,
           CMN_CONFIG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_SPARE,
           CMN_CONFIG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_RX_EDGE_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_RX_EDGE_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_RX_EDGE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_RX_EDGE_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_RX_EDGE_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_RX_EDGE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_RX_EDGE_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.setBit<CMN_CONFIG_RX_EDGE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_RX_EDGE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CMN_CONFIG_RX_EDGE_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.clearBit<CMN_CONFIG_RX_EDGE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_RX_EDGE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_RX_EDGE_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_RX_EDGE_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_RX_EDGE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CMN_CONFIG_RX_EDGE_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.getBit<CMN_CONFIG_RX_EDGE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_RX_EDGE_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_RX_EDGE_MARGIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_RX_EDGE_MARGIN,
           CMN_CONFIG_RX_EDGE_MARGIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_RX_EDGE_MARGIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_RX_EDGE_MARGIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_RX_EDGE_MARGIN,
           CMN_CONFIG_RX_EDGE_MARGIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_RX_EDGE_MARGIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_RX_EDGE_MARGIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_RX_EDGE_MARGIN,
           CMN_CONFIG_RX_EDGE_MARGIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_RX_EDGE_MARGIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_PSAV_STS_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_PSAV_STS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_PSAV_STS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_PSAV_STS_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_PSAV_STS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_PSAV_STS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_PSAV_STS_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.setBit<CMN_CONFIG_PSAV_STS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_PSAV_STS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CMN_CONFIG_PSAV_STS_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.clearBit<CMN_CONFIG_PSAV_STS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_PSAV_STS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_PSAV_STS_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_PSAV_STS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_PSAV_STS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CMN_CONFIG_PSAV_STS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.getBit<CMN_CONFIG_PSAV_STS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_PSAV_STS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_RECAL_TIMER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_RECAL_TIMER,
           CMN_CONFIG_RECAL_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_RECAL_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_RECAL_TIMER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_RECAL_TIMER,
           CMN_CONFIG_RECAL_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_RECAL_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_RECAL_TIMER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_RECAL_TIMER,
           CMN_CONFIG_RECAL_TIMER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_RECAL_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_1US_TMR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_1US_TMR,
           CMN_CONFIG_1US_TMR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_1US_TMR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_1US_TMR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_1US_TMR,
           CMN_CONFIG_1US_TMR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_1US_TMR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_1US_TMR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_1US_TMR,
           CMN_CONFIG_1US_TMR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_1US_TMR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_DBG_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_DBG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_DBG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_DBG_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_DBG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_DBG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_DBG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.setBit<CMN_CONFIG_DBG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_DBG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CMN_CONFIG_DBG_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.clearBit<CMN_CONFIG_DBG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_DBG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_DBG_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_DBG_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_DBG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CMN_CONFIG_DBG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.getBit<CMN_CONFIG_DBG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_DBG_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_DBG_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_DBG_SEL,
           CMN_CONFIG_DBG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_DBG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_DBG_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_DBG_SEL,
           CMN_CONFIG_DBG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_DBG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_DBG_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_DBG_SEL,
           CMN_CONFIG_DBG_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_DBG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_RD_RST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_RD_RST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_RD_RST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_RD_RST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_RD_RST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_RD_RST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_RD_RST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.setBit<CMN_CONFIG_RD_RST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_RD_RST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CMN_CONFIG_RD_RST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.clearBit<CMN_CONFIG_RD_RST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_RD_RST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_RD_RST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_RD_RST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_RD_RST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CMN_CONFIG_RD_RST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.getBit<CMN_CONFIG_RD_RST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_RD_RST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_PRE_SCALAR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_PRE_SCALAR,
           CMN_CONFIG_PRE_SCALAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_PRE_SCALAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_PRE_SCALAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_PRE_SCALAR,
           CMN_CONFIG_PRE_SCALAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_PRE_SCALAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_PRE_SCALAR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_PRE_SCALAR,
           CMN_CONFIG_PRE_SCALAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_PRE_SCALAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_FREEZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_FREEZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.setBit<CMN_CONFIG_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CMN_CONFIG_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.clearBit<CMN_CONFIG_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_FREEZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_FREEZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CMN_CONFIG_FREEZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.getBit<CMN_CONFIG_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_PORT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_PORT_SEL,
           CMN_CONFIG_PORT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_PORT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_PORT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_PORT_SEL,
           CMN_CONFIG_PORT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_PORT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_PORT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_PORT_SEL,
           CMN_CONFIG_PORT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_PORT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR3_PS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR3_PS,
           CMN_CONFIG_CNTR3_PS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR3_PS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR3_PS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR3_PS,
           CMN_CONFIG_CNTR3_PS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR3_PS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_CNTR3_PS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_CNTR3_PS,
           CMN_CONFIG_CNTR3_PS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR3_PS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR3_ES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR3_ES,
           CMN_CONFIG_CNTR3_ES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR3_ES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR3_ES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR3_ES,
           CMN_CONFIG_CNTR3_ES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR3_ES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_CNTR3_ES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_CNTR3_ES,
           CMN_CONFIG_CNTR3_ES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR3_ES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR2_PS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR2_PS,
           CMN_CONFIG_CNTR2_PS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR2_PS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR2_PS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR2_PS,
           CMN_CONFIG_CNTR2_PS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR2_PS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_CNTR2_PS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_CNTR2_PS,
           CMN_CONFIG_CNTR2_PS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR2_PS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR2_ES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR2_ES,
           CMN_CONFIG_CNTR2_ES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR2_ES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR2_ES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR2_ES,
           CMN_CONFIG_CNTR2_ES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR2_ES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_CNTR2_ES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_CNTR2_ES,
           CMN_CONFIG_CNTR2_ES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR2_ES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR1_PS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR1_PS,
           CMN_CONFIG_CNTR1_PS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR1_PS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR1_PS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR1_PS,
           CMN_CONFIG_CNTR1_PS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR1_PS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_CNTR1_PS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_CNTR1_PS,
           CMN_CONFIG_CNTR1_PS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR1_PS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR1_ES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR1_ES,
           CMN_CONFIG_CNTR1_ES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR1_ES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR1_ES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR1_ES,
           CMN_CONFIG_CNTR1_ES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR1_ES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_CNTR1_ES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_CNTR1_ES,
           CMN_CONFIG_CNTR1_ES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR1_ES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR0_PS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR0_PS,
           CMN_CONFIG_CNTR0_PS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR0_PS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR0_PS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR0_PS,
           CMN_CONFIG_CNTR0_PS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR0_PS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_CNTR0_PS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_CNTR0_PS,
           CMN_CONFIG_CNTR0_PS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR0_PS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR0_ES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR0_ES,
           CMN_CONFIG_CNTR0_ES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR0_ES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR0_ES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR0_ES,
           CMN_CONFIG_CNTR0_ES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR0_ES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_CNTR0_ES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_CNTR0_ES,
           CMN_CONFIG_CNTR0_ES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR0_ES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR3_PE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR3_PE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR3_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR3_PE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR3_PE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR3_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR3_PE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.setBit<CMN_CONFIG_CNTR3_PE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR3_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CMN_CONFIG_CNTR3_PE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.clearBit<CMN_CONFIG_CNTR3_PE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR3_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_CNTR3_PE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_CNTR3_PE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR3_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CMN_CONFIG_CNTR3_PE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.getBit<CMN_CONFIG_CNTR3_PE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR3_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR2_PE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR2_PE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR2_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR2_PE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR2_PE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR2_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR2_PE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.setBit<CMN_CONFIG_CNTR2_PE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR2_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CMN_CONFIG_CNTR2_PE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.clearBit<CMN_CONFIG_CNTR2_PE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR2_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_CNTR2_PE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_CNTR2_PE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR2_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CMN_CONFIG_CNTR2_PE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.getBit<CMN_CONFIG_CNTR2_PE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR2_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR1_PE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR1_PE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR1_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR1_PE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR1_PE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR1_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR1_PE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.setBit<CMN_CONFIG_CNTR1_PE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR1_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CMN_CONFIG_CNTR1_PE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.clearBit<CMN_CONFIG_CNTR1_PE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR1_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_CNTR1_PE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_CNTR1_PE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR1_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CMN_CONFIG_CNTR1_PE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.getBit<CMN_CONFIG_CNTR1_PE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR1_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR0_PE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR0_PE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR0_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR0_PE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR0_PE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR0_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR0_PE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.setBit<CMN_CONFIG_CNTR0_PE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR0_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CMN_CONFIG_CNTR0_PE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.clearBit<CMN_CONFIG_CNTR0_PE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR0_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_CNTR0_PE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_CNTR0_PE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR0_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CMN_CONFIG_CNTR0_PE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.getBit<CMN_CONFIG_CNTR0_PE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR0_PE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR3_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR3_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR3_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR3_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR3_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR3_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR3_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.setBit<CMN_CONFIG_CNTR3_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR3_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CMN_CONFIG_CNTR3_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.clearBit<CMN_CONFIG_CNTR3_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR3_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_CNTR3_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_CNTR3_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR3_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CMN_CONFIG_CNTR3_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.getBit<CMN_CONFIG_CNTR3_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR3_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR2_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR2_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR2_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR2_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR2_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR2_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR2_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.setBit<CMN_CONFIG_CNTR2_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR2_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CMN_CONFIG_CNTR2_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.clearBit<CMN_CONFIG_CNTR2_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR2_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_CNTR2_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_CNTR2_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR2_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CMN_CONFIG_CNTR2_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.getBit<CMN_CONFIG_CNTR2_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR2_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR1_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR1_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR1_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR1_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR1_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR1_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR1_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.setBit<CMN_CONFIG_CNTR1_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR1_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CMN_CONFIG_CNTR1_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.clearBit<CMN_CONFIG_CNTR1_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR1_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_CNTR1_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_CNTR1_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR1_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CMN_CONFIG_CNTR1_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.getBit<CMN_CONFIG_CNTR1_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR1_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR0_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR0_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR0_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.insertFromRight<CMN_CONFIG_CNTR0_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CMN_CONFIG_CNTR0_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.setBit<CMN_CONFIG_CNTR0_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CMN_CONFIG_CNTR0_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return o_data.clearBit<CMN_CONFIG_CNTR0_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CMN_CONFIG_CNTR0_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.extractToRight<CMN_CONFIG_CNTR0_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CMN_CONFIG_CNTR0_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CMN_CONFIG));
#endif
    return i_data.getBit<CMN_CONFIG_CNTR0_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CMN_CONFIG_CNTR0_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE14_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE14_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE14_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE14_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE14_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE14_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE14_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE14_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE14_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE14_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE14_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE14_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE14_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE14_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE1_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE1_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE1_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE1_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE1_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE1_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE1_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE1_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE1_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE1_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE1_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE1_PG_16TO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE1_PG_16TO1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE1_PG_16TO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE1_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE1_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE1_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE1_PG_16TO1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE1_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_TX_CNTL6_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL6_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_TX_CNTL6_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL6_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_TX_CNTL6_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_TX_CNTL6_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL6_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_TX_CNTL6_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL6_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH,
           CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL6_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH,
           CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL6_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH,
           CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT16_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT16_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT16_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT16_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT16_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT16_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT16_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT16_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT16_PG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT16_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT16_PG_0,
           DATASM_REGS_RX_CNT16_PG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT16_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT16_PG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT16_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT16_PG_0,
           DATASM_REGS_RX_CNT16_PG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT16_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT16_PG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT16_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT16_PG_0,
           DATASM_REGS_RX_CNT16_PG_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT16_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT16_PG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT16_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT16_PG_1,
           DATASM_REGS_RX_CNT16_PG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT16_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT16_PG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT16_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT16_PG_1,
           DATASM_REGS_RX_CNT16_PG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT16_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT16_PG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT16_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT16_PG_1,
           DATASM_REGS_RX_CNT16_PG_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT16_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT26_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT26_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT26_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT26_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT26_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT26_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT26_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT26_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT26_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23,
           DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT26_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23,
           DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT26_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23,
           DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL5_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL5_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNTL5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL5_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNTL5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15,
           DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15,
           DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL5_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15,
           DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_STAT5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT5_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_STAT5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT5_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_STAT5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_STAT5_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT5_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_STAT5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_CTLSM_CNTL7_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL7_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_CTLSM_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL7_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL7_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_CTLSM_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL7_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL7_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL7_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15,
           TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL7_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15,
           TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL7_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15,
           TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
