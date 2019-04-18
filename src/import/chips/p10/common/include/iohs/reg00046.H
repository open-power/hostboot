/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00046.H $         */
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

#ifndef __IOHS_REG00046_H_
#define __IOHS_REG00046_H_

namespace scomt
{
namespace iohs
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_CLK_REGION(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18030006;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_CLK_REGION(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18030006;
#endif
    return fapi2::getScom(i_target, AXON_CLK_REGION, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_CLK_REGION(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return fapi2::putScom(i_target, AXON_CLK_REGION, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_CMD,
           AXON_CLK_REGION_CLOCK_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_CMD,
           AXON_CLK_REGION_CLOCK_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_CMD,
           AXON_CLK_REGION_CLOCK_CMD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_SLAVE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_SLAVE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_SLAVE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_SLAVE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_SLAVE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_SLAVE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_SLAVE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_SLAVE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_SLAVE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_SLAVE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_SLAVE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_SLAVE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_MASTER_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_MASTER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_MASTER_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_MASTER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_MASTER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_MASTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_MASTER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_MASTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_MASTER_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_MASTER_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_MASTER_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_MASTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_CLOCK_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_CLOCK_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_CLOCK_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_REGION_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_CLOCK_REGION_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_CLOCK_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_CLOCK_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_CLOCK_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_CLOCK_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_REGION_UNIT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_CLOCK_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_CLOCK_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_CLOCK_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_CLOCK_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_CLOCK_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_REGION_UNIT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_CLOCK_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_CLOCK_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_CLOCK_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_CLOCK_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_CLOCK_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_REGION_UNIT3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_CLOCK_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_CLOCK_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_CLOCK_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_CLOCK_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_CLOCK_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_REGION_UNIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_CLOCK_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_CLOCK_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_CLOCK_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_CLOCK_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_CLOCK_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_REGION_UNIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_CLOCK_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_CLOCK_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_CLOCK_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_CLOCK_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_CLOCK_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_REGION_UNIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_CLOCK_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_CLOCK_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_CLOCK_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_CLOCK_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_CLOCK_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_REGION_UNIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_CLOCK_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_CLOCK_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_CLOCK_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_CLOCK_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_CLOCK_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_REGION_UNIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_CLOCK_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_CLOCK_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_CLOCK_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_CLOCK_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_CLOCK_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_REGION_UNIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_CLOCK_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_CLOCK_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_CLOCK_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_CLOCK_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_CLOCK_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_REGION_UNIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_CLOCK_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_CLOCK_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_CLOCK_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_CLOCK_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_CLOCK_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_REGION_UNIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_CLOCK_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_CLOCK_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_CLOCK_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_CLOCK_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_CLOCK_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_REGION_UNIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_CLOCK_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_CLOCK_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_CLOCK_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_CLOCK_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_CLOCK_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_REGION_UNIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_CLOCK_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_CLOCK_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_CLOCK_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_CLOCK_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_CLOCK_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_REGION_UNIT14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_CLOCK_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_CLOCK_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_SEL_THOLD_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_SEL_THOLD_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SEL_THOLD_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_SEL_THOLD_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_SEL_THOLD_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SEL_THOLD_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_SEL_THOLD_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_SEL_THOLD_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SEL_THOLD_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_SEL_THOLD_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_SEL_THOLD_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SEL_THOLD_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_SEL_THOLD_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_SEL_THOLD_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SEL_THOLD_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_SEL_THOLD_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_SEL_THOLD_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SEL_THOLD_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_SEL_THOLD_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_SEL_THOLD_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SEL_THOLD_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_SEL_THOLD_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_SEL_THOLD_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SEL_THOLD_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_SEL_THOLD_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_SEL_THOLD_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SEL_THOLD_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_SEL_THOLD_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_SEL_THOLD_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SEL_THOLD_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_SEL_THOLD_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_SEL_THOLD_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SEL_THOLD_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_SEL_THOLD_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_SEL_THOLD_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SEL_THOLD_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_SEL_THOLD_ARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_SEL_THOLD_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SEL_THOLD_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_SEL_THOLD_ARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_SEL_THOLD_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SEL_THOLD_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_SEL_THOLD_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_SEL_THOLD_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SEL_THOLD_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_SEL_THOLD_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_SEL_THOLD_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SEL_THOLD_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_SEL_THOLD_ARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_SEL_THOLD_ARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SEL_THOLD_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_SEL_THOLD_ARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_SEL_THOLD_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_SEL_THOLD_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_PULSE_USE_EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.insertFromRight<AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.setBit<AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return o_data.clearBit<AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.extractToRight<AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030006));
#endif
    return i_data.getBit<AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_CPLT_CONF0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000008;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_CPLT_CONF0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000008;
#endif
    return fapi2::getScom(i_target, AXON_CPLT_CONF0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_CPLT_CONF0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return fapi2::putScom(i_target, AXON_CPLT_CONF0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_CPLT_CONF0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000028;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_CPLT_CONF0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000028;
#endif
    return fapi2::getScom(i_target, AXON_CPLT_CONF0_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_CPLT_CONF0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return fapi2::putScom(i_target, AXON_CPLT_CONF0_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_CPLT_CONF0_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000018;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_CPLT_CONF0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000018;
#endif
    return fapi2::getScom(i_target, AXON_CPLT_CONF0_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_CPLT_CONF0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return fapi2::putScom(i_target, AXON_CPLT_CONF0_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC,
           AXON_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC,
           AXON_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC,
           AXON_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_6G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_6G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_6G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_6G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_6G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_6G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_6G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_RESERVED_6G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_6G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_RESERVED_6G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_RESERVED_6G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_6G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_RESERVED_6G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_RESERVED_6G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_6G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_RESERVED_6G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_RESERVED_6G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_6G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_7G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_7G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_7G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_7G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_7G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_7G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_7G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_RESERVED_7G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_7G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_RESERVED_7G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_RESERVED_7G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_7G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_RESERVED_7G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_RESERVED_7G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_7G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_RESERVED_7G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_RESERVED_7G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_7G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC,
           AXON_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC,
           AXON_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC,
           AXON_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_14G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_14G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_14G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_14G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_14G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_14G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_14G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_RESERVED_14G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_14G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_RESERVED_14G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_RESERVED_14G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_14G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_RESERVED_14G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_RESERVED_14G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_14G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_RESERVED_14G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_RESERVED_14G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_14G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_15G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_15G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_15G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_15G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_15G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_15G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_15G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_RESERVED_15G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_15G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_RESERVED_15G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_RESERVED_15G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_15G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_RESERVED_15G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_RESERVED_15G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_15G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_RESERVED_15G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_RESERVED_15G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_15G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC,
           AXON_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC,
           AXON_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC,
           AXON_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_22G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_22G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_22G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_22G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_22G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_22G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_22G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_RESERVED_22G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_22G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_RESERVED_22G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_RESERVED_22G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_22G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_RESERVED_22G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_RESERVED_22G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_22G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_RESERVED_22G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_RESERVED_22G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_22G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_23G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_23G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_23G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_23G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_23G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_23G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_23G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_RESERVED_23G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_23G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_RESERVED_23G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_RESERVED_23G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_23G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_RESERVED_23G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_RESERVED_23G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_23G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_RESERVED_23G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_RESERVED_23G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_23G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC,
           AXON_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC,
           AXON_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC,
           AXON_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_30G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_30G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_30G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_30G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_30G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_30G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_30G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_RESERVED_30G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_30G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_RESERVED_30G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_RESERVED_30G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_30G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_RESERVED_30G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_RESERVED_30G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_30G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_RESERVED_30G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_RESERVED_30G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_30G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_31G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_31G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_31G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_31G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_31G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_31G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_31G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_RESERVED_31G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_31G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_RESERVED_31G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_RESERVED_31G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_31G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_RESERVED_31G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_RESERVED_31G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_31G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_RESERVED_31G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_RESERVED_31G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_31G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_SDIS_DC_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_36G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_37G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_38G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_TEST_CONTROL_39G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_42G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_42G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_42G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_42G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_42G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_42G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_42G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_RESERVED_42G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_42G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_RESERVED_42G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_RESERVED_42G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_42G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_RESERVED_42G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_RESERVED_42G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_42G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_RESERVED_42G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_RESERVED_42G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_42G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_43G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_43G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_43G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_43G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_RESERVED_43G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_43G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_RESERVED_43G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_RESERVED_43G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_43G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_RESERVED_43G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_RESERVED_43G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_43G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_RESERVED_43G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_RESERVED_43G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_43G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_RESERVED_43G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_RESERVED_43G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_RESERVED_43G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_TC_IOO_EOL_TOGL_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_TC_SKIT_CANARY_MODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_47G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_47G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_47G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_47G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_47G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_47G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_47G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_FREE_USAGE_47G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_47G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_FREE_USAGE_47G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_FREE_USAGE_47G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_47G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_FREE_USAGE_47G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_FREE_USAGE_47G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_47G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_FREE_USAGE_47G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_FREE_USAGE_47G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_47G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_48G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_48G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_48G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_48G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_48G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_48G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_48G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_FREE_USAGE_48G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_48G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_FREE_USAGE_48G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_FREE_USAGE_48G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_48G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_FREE_USAGE_48G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_FREE_USAGE_48G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_48G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_FREE_USAGE_48G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_FREE_USAGE_48G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_48G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_49G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_49G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_49G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_49G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_49G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_49G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_49G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_FREE_USAGE_49G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_49G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_FREE_USAGE_49G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_FREE_USAGE_49G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_49G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_FREE_USAGE_49G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_FREE_USAGE_49G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_49G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_FREE_USAGE_49G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_FREE_USAGE_49G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_49G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_50G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_50G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_50G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_50G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_50G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_50G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_50G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_FREE_USAGE_50G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_50G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_FREE_USAGE_50G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_FREE_USAGE_50G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_50G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_FREE_USAGE_50G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_FREE_USAGE_50G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_50G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_FREE_USAGE_50G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_FREE_USAGE_50G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_50G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_51G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_51G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_51G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_51G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_51G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_51G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_51G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_FREE_USAGE_51G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_51G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_FREE_USAGE_51G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_FREE_USAGE_51G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_51G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_FREE_USAGE_51G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_FREE_USAGE_51G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_51G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_FREE_USAGE_51G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_FREE_USAGE_51G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_51G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_52G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_52G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_52G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_52G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_52G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_52G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_52G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_FREE_USAGE_52G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_52G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_FREE_USAGE_52G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_FREE_USAGE_52G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_52G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_FREE_USAGE_52G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_FREE_USAGE_52G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_52G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_FREE_USAGE_52G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_FREE_USAGE_52G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_52G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_53G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_53G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_53G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_53G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_53G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_53G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_53G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_FREE_USAGE_53G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_53G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_FREE_USAGE_53G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_FREE_USAGE_53G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_53G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_FREE_USAGE_53G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_FREE_USAGE_53G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_53G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_FREE_USAGE_53G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_FREE_USAGE_53G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_53G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_54G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_54G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_54G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_54G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_54G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_54G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_54G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_FREE_USAGE_54G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_54G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_FREE_USAGE_54G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_FREE_USAGE_54G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_54G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_FREE_USAGE_54G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_FREE_USAGE_54G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_54G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_FREE_USAGE_54G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_FREE_USAGE_54G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_54G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_55G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_55G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_55G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_55G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_55G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_55G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_55G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_FREE_USAGE_55G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_55G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_FREE_USAGE_55G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_FREE_USAGE_55G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_55G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_FREE_USAGE_55G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_FREE_USAGE_55G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_55G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_FREE_USAGE_55G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_FREE_USAGE_55G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_55G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_56G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_56G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_56G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_56G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_56G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_56G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_56G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_FREE_USAGE_56G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_56G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_FREE_USAGE_56G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_FREE_USAGE_56G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_56G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_FREE_USAGE_56G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_FREE_USAGE_56G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_56G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_FREE_USAGE_56G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_FREE_USAGE_56G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_56G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_57G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_57G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_57G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_57G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_57G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_57G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_57G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_FREE_USAGE_57G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_57G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_FREE_USAGE_57G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_FREE_USAGE_57G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_57G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_FREE_USAGE_57G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_FREE_USAGE_57G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_57G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_FREE_USAGE_57G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_FREE_USAGE_57G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_57G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_58G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_58G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_58G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_58G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_58G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_58G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_58G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_FREE_USAGE_58G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_58G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_FREE_USAGE_58G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_FREE_USAGE_58G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_58G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_FREE_USAGE_58G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_FREE_USAGE_58G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_58G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_FREE_USAGE_58G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_FREE_USAGE_58G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_58G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_59G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_59G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_59G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_59G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_59G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_59G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_59G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_FREE_USAGE_59G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_59G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_FREE_USAGE_59G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_FREE_USAGE_59G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_59G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_FREE_USAGE_59G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_FREE_USAGE_59G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_59G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_FREE_USAGE_59G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_FREE_USAGE_59G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_59G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_60G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_60G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_60G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_60G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_60G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_60G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_60G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_FREE_USAGE_60G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_60G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_FREE_USAGE_60G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_FREE_USAGE_60G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_60G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_FREE_USAGE_60G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_FREE_USAGE_60G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_60G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_FREE_USAGE_60G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_FREE_USAGE_60G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_60G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_61G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_61G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_61G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_61G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_61G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_61G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_61G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_FREE_USAGE_61G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_61G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_FREE_USAGE_61G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_FREE_USAGE_61G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_61G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_FREE_USAGE_61G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_FREE_USAGE_61G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_61G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_FREE_USAGE_61G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_FREE_USAGE_61G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_61G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_62G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_62G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_62G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_62G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_62G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_62G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_62G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_FREE_USAGE_62G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_62G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_FREE_USAGE_62G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_FREE_USAGE_62G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_62G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_FREE_USAGE_62G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_FREE_USAGE_62G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_62G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_FREE_USAGE_62G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_FREE_USAGE_62G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_62G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_63G(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_63G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_63G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_63G(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.insertFromRight<AXON_CPLT_CONF0_FREE_USAGE_63G,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_63G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CONF0_FREE_USAGE_63G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.setBit<AXON_CPLT_CONF0_FREE_USAGE_63G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_63G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CONF0_FREE_USAGE_63G(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return o_data.clearBit<AXON_CPLT_CONF0_FREE_USAGE_63G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_63G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CONF0_FREE_USAGE_63G(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.extractToRight<AXON_CPLT_CONF0_FREE_USAGE_63G,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_63G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CONF0_FREE_USAGE_63G(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000028, 0x18000018, 0x18000008));
#endif
    return i_data.getBit<AXON_CPLT_CONF0_FREE_USAGE_63G>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CONF0_FREE_USAGE_63G chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_CPLT_CTRL0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000000;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_CPLT_CTRL0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000000;
#endif
    return fapi2::getScom(i_target, AXON_CPLT_CTRL0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_CPLT_CTRL0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return fapi2::putScom(i_target, AXON_CPLT_CTRL0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_CPLT_CTRL0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000020;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_CPLT_CTRL0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000020;
#endif
    return fapi2::getScom(i_target, AXON_CPLT_CTRL0_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_CPLT_CTRL0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return fapi2::putScom(i_target, AXON_CPLT_CTRL0_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_CPLT_CTRL0_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000010;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_CPLT_CTRL0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18000010;
#endif
    return fapi2::getScom(i_target, AXON_CPLT_CTRL0_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_CPLT_CTRL0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return fapi2::putScom(i_target, AXON_CPLT_CTRL0_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_11A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_11A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_11A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_RESERVED_11A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_RESERVED_11A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_RESERVED_11A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_RESERVED_11A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_SKIT_MODE_BIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_18A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_18A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_18A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_RESERVED_18A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_RESERVED_18A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_RESERVED_18A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_RESERVED_18A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_19A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_19A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_19A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_RESERVED_19A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_RESERVED_19A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_RESERVED_19A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_RESERVED_19A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_PSRO_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_PSRO_SEL_DC,
           AXON_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_PSRO_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_PSRO_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_PSRO_SEL_DC,
           AXON_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_PSRO_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_TC_PSRO_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_TC_PSRO_SEL_DC,
           AXON_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_PSRO_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_WRAPSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_INTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_BSC_INV_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_BSC_INV_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_INV_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_BSC_INV_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_BSC_INV_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_INV_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_BSC_INV_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_TC_BSC_INV_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_INV_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_TC_BSC_INV_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_TC_BSC_INV_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_INV_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_TC_BSC_INV_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_TC_BSC_INV_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_INV_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_TC_BSC_INV_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_TC_BSC_INV_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_INV_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_TC_BSC_EXTMODE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_33A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_33A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_33A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_RESERVED_33A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_RESERVED_33A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_RESERVED_33A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_RESERVED_33A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_34A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_34A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_34A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_RESERVED_34A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_RESERVED_34A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_RESERVED_34A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_RESERVED_34A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_35A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_35A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_35A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_RESERVED_35A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_RESERVED_35A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_RESERVED_35A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_RESERVED_35A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_36A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_36A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_36A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_36A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_36A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_36A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_36A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_RESERVED_36A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_36A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_RESERVED_36A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_RESERVED_36A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_36A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_RESERVED_36A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_RESERVED_36A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_36A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_RESERVED_36A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_RESERVED_36A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_36A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_37A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_37A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_37A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_37A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_37A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_37A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_37A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_RESERVED_37A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_37A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_RESERVED_37A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_RESERVED_37A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_37A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_RESERVED_37A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_RESERVED_37A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_37A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_RESERVED_37A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_RESERVED_37A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_37A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_38A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_38A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_38A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_RESERVED_38A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_RESERVED_38A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_RESERVED_38A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_RESERVED_38A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_39A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_39A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_39A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_RESERVED_39A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_RESERVED_39A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_RESERVED_39A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_RESERVED_39A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC,
           AXON_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC,
           AXON_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC,
           AXON_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_42A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_42A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_42A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_RESERVED_42A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_RESERVED_42A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_RESERVED_42A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_RESERVED_42A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_43A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_43A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_RESERVED_43A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_RESERVED_43A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_RESERVED_43A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_RESERVED_43A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_RESERVED_43A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_DCTEST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_48A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_48A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_48A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_FREE_USAGE_48A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_FREE_USAGE_48A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_FREE_USAGE_48A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_FREE_USAGE_48A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_49A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_49A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_49A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_FREE_USAGE_49A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_FREE_USAGE_49A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_FREE_USAGE_49A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_FREE_USAGE_49A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_50A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_50A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_50A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_FREE_USAGE_50A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_FREE_USAGE_50A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_FREE_USAGE_50A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_FREE_USAGE_50A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_51A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_51A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_51A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_FREE_USAGE_51A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_FREE_USAGE_51A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_FREE_USAGE_51A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_FREE_USAGE_51A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_52A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_52A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_52A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_FREE_USAGE_52A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_FREE_USAGE_52A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_FREE_USAGE_52A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_FREE_USAGE_52A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_53A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_53A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_53A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_FREE_USAGE_53A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_FREE_USAGE_53A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_FREE_USAGE_53A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_FREE_USAGE_53A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_54A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_54A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_54A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_FREE_USAGE_54A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_FREE_USAGE_54A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_FREE_USAGE_54A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_FREE_USAGE_54A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_55A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_55A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_55A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_55A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_55A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_FREE_USAGE_55A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_FREE_USAGE_55A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_FREE_USAGE_55A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_FREE_USAGE_55A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_FREE_USAGE_55A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_FREE_USAGE_55A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_FREE_USAGE_55A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_56A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_56A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_56A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_FREE_USAGE_56A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_FREE_USAGE_56A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_FREE_USAGE_56A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_FREE_USAGE_56A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_57A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_57A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_57A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_FREE_USAGE_57A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_FREE_USAGE_57A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_FREE_USAGE_57A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_FREE_USAGE_57A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_58A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_58A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_58A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_FREE_USAGE_58A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_FREE_USAGE_58A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_FREE_USAGE_58A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_FREE_USAGE_58A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_59A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_59A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_59A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_FREE_USAGE_59A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_FREE_USAGE_59A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_FREE_USAGE_59A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_FREE_USAGE_59A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_60A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_60A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_60A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_FREE_USAGE_60A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_FREE_USAGE_60A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_FREE_USAGE_60A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_FREE_USAGE_60A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_61A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_61A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_61A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_FREE_USAGE_61A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_FREE_USAGE_61A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_FREE_USAGE_61A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_FREE_USAGE_61A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_62A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_62A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_62A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_FREE_USAGE_62A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_FREE_USAGE_62A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_FREE_USAGE_62A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_FREE_USAGE_62A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_63A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_63A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.insertFromRight<AXON_CPLT_CTRL0_FREE_USAGE_63A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.setBit<AXON_CPLT_CTRL0_FREE_USAGE_63A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return o_data.clearBit<AXON_CPLT_CTRL0_FREE_USAGE_63A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.extractToRight<AXON_CPLT_CTRL0_FREE_USAGE_63A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18000020, 0x18000010, 0x18000000));
#endif
    return i_data.getBit<AXON_CPLT_CTRL0_FREE_USAGE_63A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18010005;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18010005;
#endif
    return fapi2::getScom(i_target, AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x18010005));
#endif
    return fapi2::putScom(i_target, AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010005));
#endif
    return o_data.insertFromRight<AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010005));
#endif
    return o_data.insertFromRight<AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010005));
#endif
    return o_data.setBit<AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010005));
#endif
    return o_data.clearBit<AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010005));
#endif
    return i_data.extractToRight<AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010005));
#endif
    return i_data.getBit<AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010005));
#endif
    return o_data.insertFromRight<AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010005));
#endif
    return o_data.insertFromRight<AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010005));
#endif
    return o_data.setBit<AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010005));
#endif
    return o_data.clearBit<AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010005));
#endif
    return i_data.extractToRight<AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010005));
#endif
    return i_data.getBit<AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_LOCAL_XSTOP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18040018;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_LOCAL_XSTOP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18040018;
#endif
    return fapi2::getScom(i_target, AXON_LOCAL_XSTOP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_LOCAL_XSTOP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return fapi2::putScom(i_target, AXON_LOCAL_XSTOP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.setBit<AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.clearBit<AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.extractToRight<AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.getBit<AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_RESERVED1L(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_RESERVED1L,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_RESERVED1L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_RESERVED1L(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_RESERVED1L,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_RESERVED1L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_RESERVED1L(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.setBit<AXON_LOCAL_XSTOP_RESERVED1L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_RESERVED1L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_XSTOP_RESERVED1L(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.clearBit<AXON_LOCAL_XSTOP_RESERVED1L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_RESERVED1L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_XSTOP_RESERVED1L(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.extractToRight<AXON_LOCAL_XSTOP_RESERVED1L,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_RESERVED1L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_XSTOP_RESERVED1L(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.getBit<AXON_LOCAL_XSTOP_RESERVED1L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_RESERVED1L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_RESERVED2L(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_RESERVED2L,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_RESERVED2L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_RESERVED2L(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_RESERVED2L,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_RESERVED2L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_RESERVED2L(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.setBit<AXON_LOCAL_XSTOP_RESERVED2L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_RESERVED2L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_XSTOP_RESERVED2L(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.clearBit<AXON_LOCAL_XSTOP_RESERVED2L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_RESERVED2L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_XSTOP_RESERVED2L(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.extractToRight<AXON_LOCAL_XSTOP_RESERVED2L,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_RESERVED2L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_XSTOP_RESERVED2L(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.getBit<AXON_LOCAL_XSTOP_RESERVED2L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_RESERVED2L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_RESERVED3L(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_RESERVED3L,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_RESERVED3L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_RESERVED3L(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_RESERVED3L,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_RESERVED3L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_RESERVED3L(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.setBit<AXON_LOCAL_XSTOP_RESERVED3L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_RESERVED3L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_XSTOP_RESERVED3L(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.clearBit<AXON_LOCAL_XSTOP_RESERVED3L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_RESERVED3L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_XSTOP_RESERVED3L(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.extractToRight<AXON_LOCAL_XSTOP_RESERVED3L,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_RESERVED3L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_XSTOP_RESERVED3L(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.getBit<AXON_LOCAL_XSTOP_RESERVED3L>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_RESERVED3L chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.setBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.clearBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.extractToRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.getBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.setBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.clearBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.extractToRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.getBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.setBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.clearBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.extractToRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.getBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.setBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.clearBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.extractToRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.getBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.setBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.clearBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.extractToRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.getBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.setBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.clearBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.extractToRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.getBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.setBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.clearBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.extractToRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.getBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.setBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.clearBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.extractToRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.getBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.setBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.clearBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.extractToRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.getBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.setBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.clearBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.extractToRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.getBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.setBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.clearBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.extractToRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.getBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.insertFromRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.setBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return o_data.clearBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.extractToRight<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040018));
#endif
    return i_data.getBit<AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_LOCAL_XSTOP_LOCAL_XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_OPCG_ALIGN(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18030001;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_OPCG_ALIGN(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18030001;
#endif
    return fapi2::getScom(i_target, AXON_OPCG_ALIGN, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_OPCG_ALIGN(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return fapi2::putScom(i_target, AXON_OPCG_ALIGN, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_INOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_INOP_ALIGN,
           AXON_OPCG_ALIGN_INOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_INOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_INOP_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_INOP_ALIGN,
           AXON_OPCG_ALIGN_INOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_INOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_ALIGN_INOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return i_data.extractToRight<AXON_OPCG_ALIGN_INOP_ALIGN,
           AXON_OPCG_ALIGN_INOP_ALIGN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_INOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_SNOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_SNOP_ALIGN,
           AXON_OPCG_ALIGN_SNOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_SNOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_SNOP_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_SNOP_ALIGN,
           AXON_OPCG_ALIGN_SNOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_SNOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_ALIGN_SNOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return i_data.extractToRight<AXON_OPCG_ALIGN_SNOP_ALIGN,
           AXON_OPCG_ALIGN_SNOP_ALIGN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_SNOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_ENOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_ENOP_ALIGN,
           AXON_OPCG_ALIGN_ENOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_ENOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_ENOP_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_ENOP_ALIGN,
           AXON_OPCG_ALIGN_ENOP_ALIGN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_ENOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_ALIGN_ENOP_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return i_data.extractToRight<AXON_OPCG_ALIGN_ENOP_ALIGN,
           AXON_OPCG_ALIGN_ENOP_ALIGN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_ENOP_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_INOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_INOP_WAIT,
           AXON_OPCG_ALIGN_INOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_INOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_INOP_WAIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_INOP_WAIT,
           AXON_OPCG_ALIGN_INOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_INOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_ALIGN_INOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return i_data.extractToRight<AXON_OPCG_ALIGN_INOP_WAIT,
           AXON_OPCG_ALIGN_INOP_WAIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_INOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_SNOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_SNOP_WAIT,
           AXON_OPCG_ALIGN_SNOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_SNOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_SNOP_WAIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_SNOP_WAIT,
           AXON_OPCG_ALIGN_SNOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_SNOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_ALIGN_SNOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return i_data.extractToRight<AXON_OPCG_ALIGN_SNOP_WAIT,
           AXON_OPCG_ALIGN_SNOP_WAIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_SNOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_ENOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_ENOP_WAIT,
           AXON_OPCG_ALIGN_ENOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_ENOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_ENOP_WAIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_ENOP_WAIT,
           AXON_OPCG_ALIGN_ENOP_WAIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_ENOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_ALIGN_ENOP_WAIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return i_data.extractToRight<AXON_OPCG_ALIGN_ENOP_WAIT,
           AXON_OPCG_ALIGN_ENOP_WAIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_ENOP_WAIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_INOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_INOP_FORCE_SG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_INOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.setBit<AXON_OPCG_ALIGN_INOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.clearBit<AXON_OPCG_ALIGN_INOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return i_data.extractToRight<AXON_OPCG_ALIGN_INOP_FORCE_SG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_OPCG_ALIGN_INOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return i_data.getBit<AXON_OPCG_ALIGN_INOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_INOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_SNOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_SNOP_FORCE_SG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_SNOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.setBit<AXON_OPCG_ALIGN_SNOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.clearBit<AXON_OPCG_ALIGN_SNOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return i_data.extractToRight<AXON_OPCG_ALIGN_SNOP_FORCE_SG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_OPCG_ALIGN_SNOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return i_data.getBit<AXON_OPCG_ALIGN_SNOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_SNOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_ENOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_ENOP_FORCE_SG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_ENOP_FORCE_SG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.setBit<AXON_OPCG_ALIGN_ENOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.clearBit<AXON_OPCG_ALIGN_ENOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return i_data.extractToRight<AXON_OPCG_ALIGN_ENOP_FORCE_SG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_OPCG_ALIGN_ENOP_FORCE_SG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return i_data.getBit<AXON_OPCG_ALIGN_ENOP_FORCE_SG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_ENOP_FORCE_SG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.setBit<AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.clearBit<AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return i_data.extractToRight<AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return i_data.getBit<AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_ALIGN_SOURCE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_ALIGN_SOURCE_SELECT,
           AXON_OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_ALIGN_SOURCE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_ALIGN_SOURCE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_ALIGN_SOURCE_SELECT,
           AXON_OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_ALIGN_SOURCE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_ALIGN_ALIGN_SOURCE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return i_data.extractToRight<AXON_OPCG_ALIGN_ALIGN_SOURCE_SELECT,
           AXON_OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_ALIGN_SOURCE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_SCAN_RATIO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_SCAN_RATIO,
           AXON_OPCG_ALIGN_SCAN_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_SCAN_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_SCAN_RATIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_SCAN_RATIO,
           AXON_OPCG_ALIGN_SCAN_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_SCAN_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_ALIGN_SCAN_RATIO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return i_data.extractToRight<AXON_OPCG_ALIGN_SCAN_RATIO,
           AXON_OPCG_ALIGN_SCAN_RATIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_SCAN_RATIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_OPCG_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_OPCG_WAIT_CYCLES,
           AXON_OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_OPCG_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_OPCG_ALIGN_OPCG_WAIT_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return o_data.insertFromRight<AXON_OPCG_ALIGN_OPCG_WAIT_CYCLES,
           AXON_OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_OPCG_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_OPCG_ALIGN_OPCG_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030001));
#endif
    return i_data.extractToRight<AXON_OPCG_ALIGN_OPCG_WAIT_CYCLES,
           AXON_OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_OPCG_ALIGN_OPCG_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_PHASE_COUNTER_RESET(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18030028;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_PHASE_COUNTER_RESET(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18030028;
#endif
    return fapi2::getScom(i_target, AXON_PHASE_COUNTER_RESET, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_PHASE_COUNTER_RESET(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x18030028));
#endif
    return fapi2::putScom(i_target, AXON_PHASE_COUNTER_RESET, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030028));
#endif
    return o_data.insertFromRight<AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030028));
#endif
    return o_data.insertFromRight<AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030028));
#endif
    return o_data.setBit<AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030028));
#endif
    return o_data.clearBit<AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030028));
#endif
    return i_data.extractToRight<AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18030028));
#endif
    return i_data.getBit<AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_PHASE_COUNTER_RESET_PHASECOUNTER_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_SCAN_UPDATEDR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1803a000;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_SCAN_UPDATEDR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x1803a000;
#endif
    return fapi2::getScom(i_target, AXON_SCAN_UPDATEDR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_SCAN_UPDATEDR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x1803a000));
#endif
    return fapi2::putScom(i_target, AXON_SCAN_UPDATEDR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_SPATTN_MASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18040007;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_SPATTN_MASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18040007;
#endif
    return fapi2::getScom(i_target, AXON_SPATTN_MASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_SPATTN_MASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return fapi2::putScom(i_target, AXON_SPATTN_MASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.insertFromRight<AXON_SPATTN_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_SPATTN_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.setBit<AXON_SPATTN_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_SPATTN_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return o_data.clearBit<AXON_SPATTN_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_SPATTN_MASK_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.extractToRight<AXON_SPATTN_MASK_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_SPATTN_MASK_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18040007));
#endif
    return i_data.getBit<AXON_SPATTN_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_AXON_TRA0_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18010409;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_AXON_TRA0_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x18010409;
#endif
    return fapi2::getScom(i_target, AXON_TRA0_TR0_CONFIG_9, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_AXON_TRA0_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return fapi2::putScom(i_target, AXON_TRA0_TR0_CONFIG_9, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.setBit<AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.clearBit<AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.getBit<AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.setBit<AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.clearBit<AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.getBit<AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_MATCHA_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_MATCHA_MUXSEL,
           AXON_TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_MATCHA_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_MATCHA_MUXSEL,
           AXON_TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_9_MATCHA_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_9_MATCHA_MUXSEL,
           AXON_TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_MATCHB_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_MATCHB_MUXSEL,
           AXON_TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_MATCHB_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_MATCHB_MUXSEL,
           AXON_TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_9_MATCHB_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_9_MATCHB_MUXSEL,
           AXON_TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_MATCHC_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_MATCHC_MUXSEL,
           AXON_TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_MATCHC_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_MATCHC_MUXSEL,
           AXON_TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_9_MATCHC_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_9_MATCHC_MUXSEL,
           AXON_TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_MATCHD_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_MATCHD_MUXSEL,
           AXON_TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_MATCHD_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_MATCHD_MUXSEL,
           AXON_TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_9_MATCHD_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_9_MATCHD_MUXSEL,
           AXON_TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG0_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_TRIG0_OR_MASK,
           AXON_TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG0_OR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_TRIG0_OR_MASK,
           AXON_TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_9_TRIG0_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_9_TRIG0_OR_MASK,
           AXON_TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG0_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_TRIG0_AND_MASK,
           AXON_TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG0_AND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_TRIG0_AND_MASK,
           AXON_TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_9_TRIG0_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_9_TRIG0_AND_MASK,
           AXON_TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG1_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_TRIG1_OR_MASK,
           AXON_TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG1_OR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_TRIG1_OR_MASK,
           AXON_TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_9_TRIG1_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_9_TRIG1_OR_MASK,
           AXON_TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG1_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_TRIG1_AND_MASK,
           AXON_TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG1_AND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_TRIG1_AND_MASK,
           AXON_TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_9_TRIG1_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_9_TRIG1_AND_MASK,
           AXON_TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.setBit<AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.clearBit<AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.getBit<AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.setBit<AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.clearBit<AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.getBit<AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_MATCH_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_MATCH_NOT_MODE,
           AXON_TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_MATCH_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_MATCH_NOT_MODE,
           AXON_TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_9_MATCH_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_9_MATCH_NOT_MODE,
           AXON_TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.setBit<AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.clearBit<AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.getBit<AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.setBit<AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.clearBit<AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.getBit<AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.setBit<AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.clearBit<AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.getBit<AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.setBit<AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.clearBit<AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.getBit<AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.insertFromRight<AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.setBit<AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return o_data.clearBit<AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.extractToRight<AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x18010409));
#endif
    return i_data.getBit<AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access AXON_TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SLAVE_CONFIG_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x180f001e;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SLAVE_CONFIG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x180f001e;
#endif
    return fapi2::getScom(i_target, SLAVE_CONFIG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SLAVE_CONFIG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return fapi2::putScom(i_target, SLAVE_CONFIG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_HEARTBEAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_HEARTBEAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_DISABLE_HEARTBEAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_DISABLE_HEARTBEAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_DISABLE_HEARTBEAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_DISABLE_HEARTBEAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_PM_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_PM_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_PM_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_PM_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_PM_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_PM_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_PM_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_PM_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_PM_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_PM_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SLAVE_CONFIG_REG_PM_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_PM_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_PM_MUX_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_PM_MUX_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_PM_MUX_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_PM_MUX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_PM_MUX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_PM_MUX_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SLAVE_CONFIG_REG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_PM_MUX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_PCBSL_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_PCBSL_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_MASK_PCBSL_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_MASK_PCBSL_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_MASK_PCBSL_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_MASK_PCBSL_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PLL_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_PLL_ERRS,
           SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_PLL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PLL_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_PLL_ERRS,
           SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_PLL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_MASK_PLL_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x180f001e));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_MASK_PLL_ERRS,
           SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SLAVE_CONFIG_REG_MASK_PLL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
