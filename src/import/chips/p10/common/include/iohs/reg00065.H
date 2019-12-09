/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00065.H $         */
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

#ifndef __IOHS_REG00065_H_
#define __IOHS_REG00065_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_DBG_CBS_CC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_DBG_CBS_CC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_DBG_CBS_CC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_DBG_CBS_CC;
#endif
    return fapi2::getScom(i_target, AXON_DBG_CBS_CC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_DBG_CBS_CC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return fapi2::putScom(i_target, AXON_DBG_CBS_CC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_RESET_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_RESET_EP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_RESET_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.setBit<AXON_DBG_CBS_CC_DBG_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.clearBit<AXON_DBG_CBS_CC_DBG_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_RESET_EP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.getBit<AXON_DBG_CBS_CC_DBG_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_OPCG_IP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_OPCG_IP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_OPCG_IP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.setBit<AXON_DBG_CBS_CC_DBG_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.clearBit<AXON_DBG_CBS_CC_DBG_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_OPCG_IP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.getBit<AXON_DBG_CBS_CC_DBG_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_VITL_CLKOFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_VITL_CLKOFF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_VITL_CLKOFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.setBit<AXON_DBG_CBS_CC_DBG_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.clearBit<AXON_DBG_CBS_CC_DBG_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_VITL_CLKOFF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.getBit<AXON_DBG_CBS_CC_DBG_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_TEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_TEST_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_TEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.setBit<AXON_DBG_CBS_CC_DBG_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.clearBit<AXON_DBG_CBS_CC_DBG_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_TEST_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.getBit<AXON_DBG_CBS_CC_DBG_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_CBS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_CBS_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_CBS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.setBit<AXON_DBG_CBS_CC_DBG_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.clearBit<AXON_DBG_CBS_CC_DBG_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_CBS_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.getBit<AXON_DBG_CBS_CC_DBG_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_CBS_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_CBS_CMD,
           AXON_DBG_CBS_CC_DBG_CBS_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CBS_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_CBS_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_CBS_CMD,
           AXON_DBG_CBS_CC_DBG_CBS_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CBS_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_CBS_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_CBS_CMD,
           AXON_DBG_CBS_CC_DBG_CBS_CMD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CBS_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_CBS_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_CBS_STATE,
           AXON_DBG_CBS_CC_DBG_CBS_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CBS_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_CBS_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_CBS_STATE,
           AXON_DBG_CBS_CC_DBG_CBS_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CBS_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_CBS_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_CBS_STATE,
           AXON_DBG_CBS_CC_DBG_CBS_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CBS_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.setBit<AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.clearBit<AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.getBit<AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.setBit<AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.clearBit<AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.getBit<AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_PCB_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_PCB_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_PCB_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.setBit<AXON_DBG_CBS_CC_DBG_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.clearBit<AXON_DBG_CBS_CC_DBG_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_PCB_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.getBit<AXON_DBG_CBS_CC_DBG_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE,
           AXON_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE,
           AXON_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE,
           AXON_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_LAST_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_LAST_OPCG_MODE,
           AXON_DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_LAST_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_LAST_OPCG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_LAST_OPCG_MODE,
           AXON_DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_LAST_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_LAST_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_LAST_OPCG_MODE,
           AXON_DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_LAST_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_PCB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_PCB_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_PCB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.setBit<AXON_DBG_CBS_CC_DBG_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.clearBit<AXON_DBG_CBS_CC_DBG_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_PCB_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.getBit<AXON_DBG_CBS_CC_DBG_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.setBit<AXON_DBG_CBS_CC_DBG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.clearBit<AXON_DBG_CBS_CC_DBG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.getBit<AXON_DBG_CBS_CC_DBG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_CC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_CC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_CC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.setBit<AXON_DBG_CBS_CC_DBG_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.clearBit<AXON_DBG_CBS_CC_DBG_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_CC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.getBit<AXON_DBG_CBS_CC_DBG_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.setBit<AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.clearBit<AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.getBit<AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.setBit<AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.clearBit<AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.getBit<AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.setBit<AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.clearBit<AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.getBit<AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.setBit<AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.clearBit<AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.getBit<AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.setBit<AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return o_data.clearBit<AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.extractToRight<AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_DBG_CBS_CC));
#endif
    return i_data.getBit<AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_EPS_DBG_XTRA_TRACE_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_EPS_DBG_XTRA_TRACE_MODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_EPS_DBG_XTRA_TRACE_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_EPS_DBG_XTRA_TRACE_MODE;
#endif
    return fapi2::getScom(i_target, AXON_EPS_DBG_XTRA_TRACE_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_EPS_DBG_XTRA_TRACE_MODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(AXON_EPS_DBG_XTRA_TRACE_MODE));
#endif
    return fapi2::putScom(i_target, AXON_EPS_DBG_XTRA_TRACE_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_DBG_XTRA_TRACE_MODE));
#endif
    return o_data.insertFromRight<AXON_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA,
           AXON_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_DBG_XTRA_TRACE_MODE));
#endif
    return o_data.insertFromRight<AXON_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA,
           AXON_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_DBG_XTRA_TRACE_MODE));
#endif
    return i_data.extractToRight<AXON_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA,
           AXON_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5;
#endif
    return fapi2::getScom(i_target, AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return fapi2::putScom(i_target, AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.insertFromRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.setBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return o_data.clearBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.extractToRight<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5));
#endif
    return i_data.getBit<AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG;
#endif
    return fapi2::getScom(i_target, AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG));
#endif
    return fapi2::putScom(i_target, AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG));
#endif
    return o_data.insertFromRight<AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK,
           AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG));
#endif
    return o_data.insertFromRight<AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK,
           AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG));
#endif
    return i_data.extractToRight<AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK,
           AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ;
#endif
    return fapi2::getScom(i_target, AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return fapi2::putScom(i_target, AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return o_data.insertFromRight<AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE,
           AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return o_data.insertFromRight<AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE,
           AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return i_data.extractToRight<AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE,
           AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return o_data.insertFromRight<AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return o_data.insertFromRight<AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return o_data.setBit<AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return o_data.clearBit<AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return i_data.extractToRight<AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return i_data.getBit<AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_ERROR_STATUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_ERROR_STATUS;
#endif
    return fapi2::getScom(i_target, AXON_ERROR_STATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return fapi2::putScom(i_target, AXON_ERROR_STATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_SCAN_COLLISION_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_SCAN_COLLISION_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_SCAN_COLLISION_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_SCAN_COLLISION_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_SCAN_COLLISION_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_SCAN_COLLISION_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_SCAN_COLLISION_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_SCAN_COLLISION_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_SCAN_COLLISION_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_SCAN_COLLISION_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_SCAN_COLLISION_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_SCAN_COLLISION_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_OPCG_TRIGGER_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_OPCG_TRIGGER_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_OPCG_TRIGGER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_OPCG_TRIGGER_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_OPCG_TRIGGER_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_OPCG_TRIGGER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_OPCG_TRIGGER_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_OPCG_TRIGGER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_OPCG_TRIGGER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_OPCG_TRIGGER_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_OPCG_TRIGGER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_OPCG_TRIGGER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_OPCG_TRIGGER_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_OPCG_TRIGGER_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_OPCG_TRIGGER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_OPCG_TRIGGER_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_OPCG_TRIGGER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_OPCG_TRIGGER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_CBS_PROTOCOL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_CBS_PROTOCOL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CBS_PROTOCOL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_CBS_PROTOCOL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_CBS_PROTOCOL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CBS_PROTOCOL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_CBS_PROTOCOL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_CBS_PROTOCOL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CBS_PROTOCOL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_CBS_PROTOCOL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_CBS_PROTOCOL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CBS_PROTOCOL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_CBS_PROTOCOL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_CBS_PROTOCOL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CBS_PROTOCOL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_CBS_PROTOCOL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_CBS_PROTOCOL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_CBS_PROTOCOL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_VITL_ALIGN_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_VITL_ALIGN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_VITL_ALIGN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_VITL_ALIGN_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_VITL_ALIGN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_VITL_ALIGN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_VITL_ALIGN_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_VITL_ALIGN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_VITL_ALIGN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_VITL_ALIGN_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_VITL_ALIGN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_VITL_ALIGN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_VITL_ALIGN_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_VITL_ALIGN_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_VITL_ALIGN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_VITL_ALIGN_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_VITL_ALIGN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_VITL_ALIGN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.insertFromRight<AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.setBit<AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return o_data.clearBit<AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.extractToRight<AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_ERROR_STATUS));
#endif
    return i_data.getBit<AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_OPCG_CAPT3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_OPCG_CAPT3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_OPCG_CAPT3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_OPCG_CAPT3;
#endif
    return fapi2::getScom(i_target, AXON_OPCG_CAPT3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_OPCG_CAPT3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return fapi2::putScom(i_target, AXON_OPCG_CAPT3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_07EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_07EVEN,
           AXON_OPCG_CAPT3_07EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_07EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_07EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_07EVEN,
           AXON_OPCG_CAPT3_07EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_07EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_CAPT3_07EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return i_data.extractToRight<AXON_OPCG_CAPT3_07EVEN,
           AXON_OPCG_CAPT3_07EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_07EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_07ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_07ODD,
           AXON_OPCG_CAPT3_07ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_07ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_07ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_07ODD,
           AXON_OPCG_CAPT3_07ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_07ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_CAPT3_07ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return i_data.extractToRight<AXON_OPCG_CAPT3_07ODD,
           AXON_OPCG_CAPT3_07ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_07ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_08EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_08EVEN,
           AXON_OPCG_CAPT3_08EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_08EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_08EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_08EVEN,
           AXON_OPCG_CAPT3_08EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_08EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_CAPT3_08EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return i_data.extractToRight<AXON_OPCG_CAPT3_08EVEN,
           AXON_OPCG_CAPT3_08EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_08EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_08ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_08ODD,
           AXON_OPCG_CAPT3_08ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_08ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_08ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_08ODD,
           AXON_OPCG_CAPT3_08ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_08ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_CAPT3_08ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return i_data.extractToRight<AXON_OPCG_CAPT3_08ODD,
           AXON_OPCG_CAPT3_08ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_08ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_09EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_09EVEN,
           AXON_OPCG_CAPT3_09EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_09EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_09EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_09EVEN,
           AXON_OPCG_CAPT3_09EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_09EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_CAPT3_09EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return i_data.extractToRight<AXON_OPCG_CAPT3_09EVEN,
           AXON_OPCG_CAPT3_09EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_09EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_09ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_09ODD,
           AXON_OPCG_CAPT3_09ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_09ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_09ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_09ODD,
           AXON_OPCG_CAPT3_09ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_09ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_CAPT3_09ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return i_data.extractToRight<AXON_OPCG_CAPT3_09ODD,
           AXON_OPCG_CAPT3_09ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_09ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_10EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_10EVEN,
           AXON_OPCG_CAPT3_10EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_10EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_10EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_10EVEN,
           AXON_OPCG_CAPT3_10EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_10EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_CAPT3_10EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return i_data.extractToRight<AXON_OPCG_CAPT3_10EVEN,
           AXON_OPCG_CAPT3_10EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_10EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_10ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_10ODD,
           AXON_OPCG_CAPT3_10ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_10ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_10ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_10ODD,
           AXON_OPCG_CAPT3_10ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_10ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_CAPT3_10ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return i_data.extractToRight<AXON_OPCG_CAPT3_10ODD,
           AXON_OPCG_CAPT3_10ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_10ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_11EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_11EVEN,
           AXON_OPCG_CAPT3_11EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_11EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_11EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_11EVEN,
           AXON_OPCG_CAPT3_11EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_11EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_CAPT3_11EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return i_data.extractToRight<AXON_OPCG_CAPT3_11EVEN,
           AXON_OPCG_CAPT3_11EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_11EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_11ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_11ODD,
           AXON_OPCG_CAPT3_11ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_11ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_11ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_11ODD,
           AXON_OPCG_CAPT3_11ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_11ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_CAPT3_11ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return i_data.extractToRight<AXON_OPCG_CAPT3_11ODD,
           AXON_OPCG_CAPT3_11ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_11ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_12EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_12EVEN,
           AXON_OPCG_CAPT3_12EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_12EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_12EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_12EVEN,
           AXON_OPCG_CAPT3_12EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_12EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_CAPT3_12EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return i_data.extractToRight<AXON_OPCG_CAPT3_12EVEN,
           AXON_OPCG_CAPT3_12EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_12EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_12ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_12ODD,
           AXON_OPCG_CAPT3_12ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_12ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_CAPT3_12ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<AXON_OPCG_CAPT3_12ODD,
           AXON_OPCG_CAPT3_12ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_12ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_CAPT3_12ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_OPCG_CAPT3));
#endif
    return i_data.extractToRight<AXON_OPCG_CAPT3_12ODD,
           AXON_OPCG_CAPT3_12ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_CAPT3_12ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_XSTOP4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_XSTOP4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_XSTOP4(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = AXON_XSTOP4;
#endif
    return fapi2::getScom(i_target, AXON_XSTOP4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_XSTOP4(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return fapi2::putScom(i_target, AXON_XSTOP4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_WAIT_SNOPA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_WAIT_SNOPA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_WAIT_SNOPA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_WAIT_SNOPA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_WAIT_SNOPA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_WAIT_SNOPA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_TRIGGER_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_TRIGGER_OPCG_GO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_TRIGGER_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_TRIGGER_OPCG_GO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_WAIT_ALWAYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_WAIT_ALWAYS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_WAIT_ALWAYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_WAIT_ALWAYS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_WAIT_ALWAYS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_WAIT_ALWAYS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_REGION_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_REGION_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_REGION_UNIT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_REGION_UNIT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_REGION_UNIT3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_REGION_UNIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_REGION_UNIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_REGION_UNIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_REGION_UNIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_REGION_UNIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_REGION_UNIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_REGION_UNIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_REGION_UNIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_REGION_UNIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_REGION_UNIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.setBit<AXON_XSTOP4_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_XSTOP4_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.clearBit<AXON_XSTOP4_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_REGION_UNIT14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_XSTOP4_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.getBit<AXON_XSTOP4_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_WAIT_CYCLES,
           AXON_XSTOP4_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_XSTOP4_WAIT_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return o_data.insertFromRight<AXON_XSTOP4_WAIT_CYCLES,
           AXON_XSTOP4_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_XSTOP4_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(AXON_XSTOP4));
#endif
    return i_data.extractToRight<AXON_XSTOP4_WAIT_CYCLES,
           AXON_XSTOP4_WAIT_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_XSTOP4_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_DLL_STATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_DLL_STATUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_DLL_STATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_DLL_STATUS;
#endif
    return fapi2::getScom(i_target, DLP_DLL_STATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_DLL_STATUS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return fapi2::putScom(i_target, DLP_DLL_STATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_PHY_TRAINING_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_PHY_TRAINING_STATE,
           DLP_DLL_STATUS_0_PHY_TRAINING_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_PHY_TRAINING_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_PHY_TRAINING_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_PHY_TRAINING_STATE,
           DLP_DLL_STATUS_0_PHY_TRAINING_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_PHY_TRAINING_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_PHY_TRAINING_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_PHY_TRAINING_STATE,
           DLP_DLL_STATUS_0_PHY_TRAINING_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_PHY_TRAINING_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_CURRENT_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_CURRENT_STATE,
           DLP_DLL_STATUS_0_CURRENT_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_CURRENT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_CURRENT_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_CURRENT_STATE,
           DLP_DLL_STATUS_0_CURRENT_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_CURRENT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_CURRENT_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_CURRENT_STATE,
           DLP_DLL_STATUS_0_CURRENT_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_CURRENT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_TIMEOUT_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_TIMEOUT_STATE,
           DLP_DLL_STATUS_0_TIMEOUT_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_TIMEOUT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_TIMEOUT_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_TIMEOUT_STATE,
           DLP_DLL_STATUS_0_TIMEOUT_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_TIMEOUT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_TIMEOUT_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_TIMEOUT_STATE,
           DLP_DLL_STATUS_0_TIMEOUT_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_TIMEOUT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_PRIOR_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_PRIOR_STATE,
           DLP_DLL_STATUS_0_PRIOR_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_PRIOR_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_PRIOR_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_PRIOR_STATE,
           DLP_DLL_STATUS_0_PRIOR_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_PRIOR_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_PRIOR_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_PRIOR_STATE,
           DLP_DLL_STATUS_0_PRIOR_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_PRIOR_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_OPTICS_RST_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_OPTICS_RST_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_OPTICS_RST_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_OPTICS_RST_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_OPTICS_RST_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_0_OPTICS_RST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_0_OPTICS_RST_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_0_OPTICS_RST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_OPTICS_RST_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_OPTICS_RST_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_DLL_STATUS_0_OPTICS_RST_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_0_OPTICS_RST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_OPTICS_IRQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_OPTICS_IRQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_OPTICS_IRQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_OPTICS_IRQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_OPTICS_IRQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_0_OPTICS_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_0_OPTICS_IRQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_0_OPTICS_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_OPTICS_IRQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_OPTICS_IRQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_DLL_STATUS_0_OPTICS_IRQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_0_OPTICS_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_TRAINING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_TRAINING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_TRAINING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_TRAINING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_TRAINING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_0_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_0_TRAINING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_0_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_TRAINING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_TRAINING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_DLL_STATUS_0_TRAINING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_0_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_MAX_PKT_TIMER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_MAX_PKT_TIMER,
           DLP_DLL_STATUS_0_MAX_PKT_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_MAX_PKT_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_MAX_PKT_TIMER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_MAX_PKT_TIMER,
           DLP_DLL_STATUS_0_MAX_PKT_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_MAX_PKT_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_MAX_PKT_TIMER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_MAX_PKT_TIMER,
           DLP_DLL_STATUS_0_MAX_PKT_TIMER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_MAX_PKT_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_PHY_TRAINING_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_PHY_TRAINING_STATE,
           DLP_DLL_STATUS_1_PHY_TRAINING_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_PHY_TRAINING_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_PHY_TRAINING_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_PHY_TRAINING_STATE,
           DLP_DLL_STATUS_1_PHY_TRAINING_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_PHY_TRAINING_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_PHY_TRAINING_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_PHY_TRAINING_STATE,
           DLP_DLL_STATUS_1_PHY_TRAINING_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_PHY_TRAINING_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_CURRENT_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_CURRENT_STATE,
           DLP_DLL_STATUS_1_CURRENT_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_CURRENT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_CURRENT_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_CURRENT_STATE,
           DLP_DLL_STATUS_1_CURRENT_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_CURRENT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_CURRENT_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_CURRENT_STATE,
           DLP_DLL_STATUS_1_CURRENT_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_CURRENT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_TIMEOUT_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_TIMEOUT_STATE,
           DLP_DLL_STATUS_1_TIMEOUT_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_TIMEOUT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_TIMEOUT_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_TIMEOUT_STATE,
           DLP_DLL_STATUS_1_TIMEOUT_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_TIMEOUT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_TIMEOUT_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_TIMEOUT_STATE,
           DLP_DLL_STATUS_1_TIMEOUT_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_TIMEOUT_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_PRIOR_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_PRIOR_STATE,
           DLP_DLL_STATUS_1_PRIOR_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_PRIOR_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_PRIOR_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_PRIOR_STATE,
           DLP_DLL_STATUS_1_PRIOR_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_PRIOR_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_PRIOR_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_PRIOR_STATE,
           DLP_DLL_STATUS_1_PRIOR_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_PRIOR_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_OPTICS_RST_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_OPTICS_RST_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_OPTICS_RST_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_OPTICS_RST_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_OPTICS_RST_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_1_OPTICS_RST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_1_OPTICS_RST_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_1_OPTICS_RST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_OPTICS_RST_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_OPTICS_RST_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_DLL_STATUS_1_OPTICS_RST_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_1_OPTICS_RST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_OPTICS_RST_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_OPTICS_IRQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_OPTICS_IRQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_OPTICS_IRQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_OPTICS_IRQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_OPTICS_IRQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_1_OPTICS_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_1_OPTICS_IRQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_1_OPTICS_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_OPTICS_IRQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_OPTICS_IRQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_DLL_STATUS_1_OPTICS_IRQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_1_OPTICS_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_OPTICS_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_TRAINING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_TRAINING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_TRAINING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_TRAINING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_TRAINING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_1_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_1_TRAINING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_1_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_TRAINING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_TRAINING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_DLL_STATUS_1_TRAINING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_1_TRAINING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_TRAINING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_MAX_PKT_TIMER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_MAX_PKT_TIMER,
           DLP_DLL_STATUS_1_MAX_PKT_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_MAX_PKT_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_MAX_PKT_TIMER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_MAX_PKT_TIMER,
           DLP_DLL_STATUS_1_MAX_PKT_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_MAX_PKT_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_MAX_PKT_TIMER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_MAX_PKT_TIMER,
           DLP_DLL_STATUS_1_MAX_PKT_TIMER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_MAX_PKT_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_LINK_UP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_LINK_UP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_LINK_UP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_LINK_UP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_LINK_UP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_0_LINK_UP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_0_LINK_UP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_0_LINK_UP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_LINK_UP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_LINK_UP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_DLL_STATUS_0_LINK_UP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_0_LINK_UP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_LINK_UP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_LINK_UP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_LINK_UP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_LINK_UP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_LINK_UP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_1_LINK_UP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_1_LINK_UP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_1_LINK_UP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_LINK_UP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_LINK_UP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_DLL_STATUS_1_LINK_UP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_1_LINK_UP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_LINK_UP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_RESET_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_RESET_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_RESET_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_RESET_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_RESET_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_0_RESET_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_0_RESET_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_0_RESET_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_RESET_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_RESET_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_DLL_STATUS_0_RESET_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_0_RESET_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_RESET_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_RESET_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_RESET_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_RESET_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_RESET_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.setBit<DLP_DLL_STATUS_1_RESET_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_DLL_STATUS_1_RESET_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.clearBit<DLP_DLL_STATUS_1_RESET_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_RESET_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_RESET_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_DLL_STATUS_1_RESET_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.getBit<DLP_DLL_STATUS_1_RESET_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_RESET_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_TDM_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_TDM_STATUS,
           DLP_DLL_STATUS_0_TDM_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_TDM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_TDM_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_TDM_STATUS,
           DLP_DLL_STATUS_0_TDM_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_TDM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_TDM_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_TDM_STATUS,
           DLP_DLL_STATUS_0_TDM_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_TDM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_TDM_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_TDM_STATUS,
           DLP_DLL_STATUS_1_TDM_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_TDM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_TDM_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_TDM_STATUS,
           DLP_DLL_STATUS_1_TDM_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_TDM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_TDM_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_TDM_STATUS,
           DLP_DLL_STATUS_1_TDM_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_TDM_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_PSAVE_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_PSAVE_STATE,
           DLP_DLL_STATUS_0_PSAVE_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_PSAVE_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_0_PSAVE_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_0_PSAVE_STATE,
           DLP_DLL_STATUS_0_PSAVE_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_PSAVE_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_0_PSAVE_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_0_PSAVE_STATE,
           DLP_DLL_STATUS_0_PSAVE_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_0_PSAVE_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_PSAVE_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_PSAVE_STATE,
           DLP_DLL_STATUS_1_PSAVE_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_PSAVE_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_DLL_STATUS_1_PSAVE_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return o_data.insertFromRight<DLP_DLL_STATUS_1_PSAVE_STATE,
           DLP_DLL_STATUS_1_PSAVE_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_PSAVE_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_DLL_STATUS_1_PSAVE_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_DLL_STATUS));
#endif
    return i_data.extractToRight<DLP_DLL_STATUS_1_PSAVE_STATE,
           DLP_DLL_STATUS_1_PSAVE_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_DLL_STATUS_1_PSAVE_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_LINK0_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK0_ERROR_STATUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_LINK0_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK0_ERROR_STATUS;
#endif
    return fapi2::getScom(i_target, DLP_LINK0_ERROR_STATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_LINK0_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return fapi2::putScom(i_target, DLP_LINK0_ERROR_STATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV,
           DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_INTERNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_INTERNAL,
           DLP_LINK0_ERROR_STATUS_INTERNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_INTERNAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_LINK0_ERROR_STATUS_INTERNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK0_ERROR_STATUS_INTERNAL,
           DLP_LINK0_ERROR_STATUS_INTERNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_INTERNAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_LINK0_ERROR_STATUS_INTERNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK0_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK0_ERROR_STATUS_INTERNAL,
           DLP_LINK0_ERROR_STATUS_INTERNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_LINK0_ERROR_STATUS_INTERNAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_PERF_TRACE_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_PERF_TRACE_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_PERF_TRACE_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_PERF_TRACE_CONFIG;
#endif
    return fapi2::getScom(i_target, DLP_PERF_TRACE_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_PERF_TRACE_CONFIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return fapi2::putScom(i_target, DLP_PERF_TRACE_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_0,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_0,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_0,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_1,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_1,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_1,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_2,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_2,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_2,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_3,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_3,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_3,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_4,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_4,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_4,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_5,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_5,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_5,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_6,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_6,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_6,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_7,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_7,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_ENABLE_PERF_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_ENABLE_PERF_7,
           DLP_PERF_TRACE_CONFIG_ENABLE_PERF_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_ENABLE_PERF_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_0,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_0,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_0,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_1,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_1,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_1,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_2,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_2,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_2,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_3,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_3,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_3,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_4,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_4,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_4,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_5,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_5,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_5,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_6,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_6,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_6,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_7,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_7,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_PERF_SIZE_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_PERF_SIZE_7,
           DLP_PERF_TRACE_CONFIG_PERF_SIZE_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_SIZE_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.setBit<DLP_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.clearBit<DLP_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.getBit<DLP_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PMULET_FREEZE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.setBit<DLP_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.clearBit<DLP_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.getBit<DLP_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_COMMON_FREEZE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_RESET_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERF_RESET_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_RESET_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERF_RESET_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERF_RESET_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.setBit<DLP_PERF_TRACE_CONFIG_PERF_RESET_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_PERF_TRACE_CONFIG_PERF_RESET_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.clearBit<DLP_PERF_TRACE_CONFIG_PERF_RESET_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_PERF_RESET_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_PERF_RESET_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_PERF_TRACE_CONFIG_PERF_RESET_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.getBit<DLP_PERF_TRACE_CONFIG_PERF_RESET_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERF_RESET_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERFTRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERFTRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERFTRACE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERFTRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERFTRACE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.setBit<DLP_PERF_TRACE_CONFIG_PERFTRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_PERF_TRACE_CONFIG_PERFTRACE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.clearBit<DLP_PERF_TRACE_CONFIG_PERFTRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_PERFTRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_PERFTRACE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_PERF_TRACE_CONFIG_PERFTRACE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.getBit<DLP_PERF_TRACE_CONFIG_PERFTRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.setBit<DLP_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.clearBit<DLP_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.getBit<DLP_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_FIXED_WINDOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.setBit<DLP_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DLP_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.clearBit<DLP_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DLP_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.getBit<DLP_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_PRESCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERFTRACE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERFTRACE_MODE,
           DLP_PERF_TRACE_CONFIG_PERFTRACE_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_PERFTRACE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_PERFTRACE_MODE,
           DLP_PERF_TRACE_CONFIG_PERFTRACE_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_PERFTRACE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_PERFTRACE_MODE,
           DLP_PERF_TRACE_CONFIG_PERFTRACE_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_PERFTRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_0,
           DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_0,
           DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_0,
           DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_1,
           DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return o_data.insertFromRight<DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_1,
           DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_PERF_TRACE_CONFIG));
#endif
    return i_data.extractToRight<DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_1,
           DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DLP_PERF_TRACE_CONFIG_TRACE_CONFIG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL,
           IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL,
           IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL,
           IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL,
           IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL,
           IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL,
           IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_REQ_ALT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_REQ_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_REQ_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_REQ_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_REQ_ALT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_STS_ALT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_STS_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_STS_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_STS_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_STS_ALT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_REQ_ALT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_REQ_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_REQ_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_REQ_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_REQ_ALT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_STS_ALT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_STS_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_STS_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_STS_ALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_STS_ALT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111,
           IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA,
           IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA,
           IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA,
           IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA,
           IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA,
           IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA,
           IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE,
           IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE,
           IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE,
           IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE,
           IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE,
           IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE,
           IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL,
           IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL,
           IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL,
           IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO,
           IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO,
           IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO,
           IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110,
           IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL,
           IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL,
           IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL,
           IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL,
           IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL,
           IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL,
           IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100,
           IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010,
           IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL,
           IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL,
           IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL,
           IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A,
           IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A,
           IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A,
           IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B,
           IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B,
           IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B,
           IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.setBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return o_data.clearBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL));
#endif
    return i_data.getBit<IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111,
           IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111,
           IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111,
           IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001,
           IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001,
           IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001,
           IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011,
           IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011,
           IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011,
           IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001,
           IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001,
           IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001,
           IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011,
           IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011,
           IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011,
           IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000,
           IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000,
           IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return i_data.extractToRight<IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000,
           IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
